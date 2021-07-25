#include "Utunes.hpp"
using namespace std;

const int DATA_ID_INDEX = 0;
const int DATA_TITLE_INDEX = 1;
const int DATA_ARTIST_INDEX = 2;
const int DATA_RELEASE_YEAR_INDEX = 3;
const int DATA_LINK_INDEX = 4;
const int NUMBER_OF_DATA_COLUMNS = 5;
const int FIRST_USER_ID = 1;
const int FIRST_PLAYLIST_ID = 1;

const std::string SUCCESS_MESSAGE = "OK\n";
const std::string ID_STRING = "id";
const std::string ARTIST_STRING = "artist";
const std::string TITLE_STRING = "title";
const std::string RELEASE_YEAR_STRING = "release_year";
const std::string LINK_STRING = "link";

const char NEXT_LINE = '\n';

Utunes::Utunes(string fileAddress)
{
    songsAddress = fileAddress;
    storeSongsData();
    loggedInUser = nullptr;
    newPlaylistID = FIRST_PLAYLIST_ID;
}

Utunes::~Utunes()
{
    for(Song* song:allSongs)
    {
        delete song;
    }
    for(User* user:users)
    {
        delete user;
    }
    for(SongFilter* filter:filters)
    {
        delete filter;
    }
}

void Utunes::storeSongsData()
{
    vector<InputLine> input = CSVParser(songsAddress).getParsedInput();
    for(int i=1; i<input.size(); i++)
    {
        storeSong(input[i]);
    }
}

void Utunes::storeSong(const InputLine& line)
{
    int id, releaseYear;
    string title, artist, link;
    id = stoi(line[DATA_ID_INDEX]);
    title = line[DATA_TITLE_INDEX];
    artist = line[DATA_ARTIST_INDEX];
    releaseYear = stoi(line[DATA_RELEASE_YEAR_INDEX]);
    link = line[DATA_LINK_INDEX];
    allSongs.push_back(new Song(id, artist, title, releaseYear, link));
}

void Utunes::execute()
{
    string input;
    while(getNewCommand(input))
    {
        try{
            CommandManager manager(input);
            executeCommand(manager.getCommand());
        } catch(exception* ex){
            reportError(ex->what());
            delete ex;
        }
    }
}


bool Utunes::getNewCommand(string& str)
{
    if(getline(cin, str))
        return true;
    else
        return false;
}

void Utunes::executeCommand(UtunesCommand* command)
{
    switch(command->getGroup())
    {
        case WRITE:
        {
            executeWriteRequest(command);
            break;
        }
        case READ:
        {
            executeReadRequest(command);
            break;
        }
        case DELETE:
        {
            executeDeleteRequest(command);
            break;
        }
    }
}

void Utunes::executeWriteRequest(UtunesCommand* command)
{
    switch(command->getType())
    {
        case SIGNUP:
        {
            signup((SignupCommand*)command);
            break;
        }
        case LOGIN:
        {
            login((LoginCommand*)command);
            break;
        }
        case LOGOUT:
        {
            logout();
            break;
        }       
        case ADD_LIKE:
        {
            addLike((AddLikeCommand*)command);
            break;
        }
        case NEW_PLAYLIST:
        {
            createNewPlaylist((NewPlaylistCommand*)command);
            return;
        }
        case ADD_SONG_PLAYLIST:
        {
            addSongToPlaylist((AddSongToPlaylistCommand*)command);
            break;
        }
        case ADD_COMMENT:
        {
            addCommentToSong((AddCommentCommand*)command);
            break;
        }
        case NEW_FILTER:
        {
            addNewFilter((NewFilterCommand*)command);
            break;
        }
    }
    reportSuccess();
}

void Utunes::executeReadRequest(UtunesCommand* command)
{
    switch(command->getType())
    {
        case GET_SONGS:
        {
            printAllSongs();
            break;
        }
        case GET_SONG:
        {
            printSong((GetSongCommand*)command);
            break;
        }
        case GET_LIKES:
        {
            printLikes();
            break;
        }
        case GET_PLAYLIST:
        {
            printPlaylistSongs((GetPlaylistCommand*)command);
            break;
        }
        case GET_PLAYLISTS:
        {
            printAllPlaylists((GetAllPlaylistsCommand*)command);
            break;
        }
        case GET_COMMENTS:
        {
            printComments((GetCommentsCommand*)command);
            break;
        }
        case GET_USERS:
        {
            printUsers((GetUsersCommand*)command);
            break;
        }
    }
}

void Utunes::executeDeleteRequest(UtunesCommand* command)
{
    switch(command->getType())
    {
        case DELETE_LIKE:
        {
            deleteLike((DeleteLikeCommand*)command);
            break;
        }
        case DELETE_SONG_PLAYLIST:
        {
            deleteSongFromPlaylist((DeleteSongFrPlaylistCommand*)command);
            break;
        }
        case DELETE_FILTERS:
        {
            deleteFilters();
            break;
        }
    }
    reportSuccess();
}

void Utunes::reportError(const string& str)
{
    cout << str;
}

void Utunes::signup(SignupCommand* command)
{
    string username = command->getUserName();
    string email = command->getEmail();
    string password = command->getPassword();
    signup(email, username, password);
}



void Utunes::checkForDuplicateUser(std::string username, std::string email)
{
    User* userByEmail = findUserByEmail(email);
    User* userByUsername = findUserByUsername(username);
    if(userByUsername != nullptr || userByEmail != nullptr)
    {
        exception* ex = new BadRequestError();
        throw ex;   
    }
}

void Utunes::checkIfUserIsInSystem(std::string email)
{
    User* user = findUserByEmail(email);
    if(user == nullptr)
    {
        userNotInSystemError();
    }
}


void Utunes::checkIfUserIsInSystem(User* user)
{
    if(user == nullptr)
    {
        userNotInSystemError();
    }
}

User* Utunes::findUserByEmail(std::string email)
{
    for(User* user:users)
    {
        if(user->getEmail() == email)
        {
            return user;
        }
    }
    return nullptr;
}

User* Utunes::findUserByUsername(std::string username)
{
    for(User* user:users)
    {
        if(user->getUsername() == username)
        {
            return user;
        }
    }
    return nullptr;
}

void Utunes::signup(std::string email, std::string username, std::string password)
{
    checkForDuplicateUser(username, password);
    users.push_back(new User(username, email, password));
    login(email, password);
}

void Utunes::login(LoginCommand* command)
{
    string email = command->getEmail();
    string password = command->getPassword();
    login(email, password);
}

void Utunes::login(std::string email, std::string password)
{
    User* user = findUserByEmail(email);
    checkIfUserIsInSystem(user);
    checkForActiveUserError();
    user->login(password);
    loggedInUser = user;
}

void Utunes::logout()
{
    checkForNoActiveUserError();
    deleteFilters();
    loggedInUser->logout();
    loggedInUser = nullptr;
}

void Utunes::checkForActiveUserError()
{
    if(loggedInUser != nullptr)
    {
        exception* ex = new PermissionDeniedError();
        throw ex;
    }
}

void Utunes::checkForNoActiveUserError()
{
    if(loggedInUser == nullptr)
    {
        exception* ex = new PermissionDeniedError();
        throw ex;
    }
}

void Utunes::reportSuccess()
{
    print(SUCCESS_MESSAGE);
}

void Utunes::userNotInSystemError()
{
    exception* ex = new BadRequestError();
    throw ex;   
}

void Utunes::print(const std::string& str)
{
    cout << str;
    cout.flush();
}


void Utunes::printAllSongs()
{
    checkForNoActiveUserError();
    vector<Song*> songs = applyFilters();
    checkForNoSongsError(songs);
    for(Song* song:songs)
    {
        print(song);
    }
}

void Utunes::print(Song* song)
{
    cout << *song << NEXT_LINE;
    cout.flush();
}

void Utunes::printSong(GetSongCommand* command)
{
    Song* song = findSongByID(command->getID());
    checkForNoActiveUserError();
    checkIfSongIsInSystem(song);
    print(song->infoInStyle() + NEXT_LINE);
}

Song* Utunes::findSongByID(int id)
{
    for(Song* song:allSongs)
    {
        if(song->getID() == id)
            return song;
    }
    return nullptr;
}

void Utunes::checkIfSongIsInSystem(Song* song)
{
    if(song == nullptr)
        songNotInSystemError();
}
    
void Utunes::songNotInSystemError()
{
    exception* ex = new NotFoundError();
    throw ex;
}

void Utunes::checkForNoSongsError(vector<Song*> songs)
{
    if(songs.empty())
    {
        exception* ex = new EmptyError();
        throw ex;
    }
}

void Utunes::addLike(AddLikeCommand* command)
{
    Song* song = findSongByID(command->getID());
    checkForNoActiveUserError();
    checkIfSongIsInSystem(song);
    loggedInUser->addLike(song);
}

void Utunes::printLikes()
{
    checkForNoActiveUserError();
    print(loggedInUser->getLikedSongs());
}

void Utunes::print(Playlist* playlist)
{
    cout << *playlist;
    cout.flush();
}

void Utunes::deleteLike(DeleteLikeCommand* command)
{
    checkForNoActiveUserError();
    Song* song = findSongByID(command->getID());
    checkIfSongIsInSystem(song);
    loggedInUser->deleteLike(song);
}

void Utunes::createNewPlaylist(NewPlaylistCommand* command)
{
    checkForNoActiveUserError(); 
    loggedInUser->addNewPlaylist(newPlaylistID, command->getName(), command->isPrivate());
    print(to_string(newPlaylistID) + "\n");
    newPlaylistID++;
}

void Utunes::addSongToPlaylist(AddSongToPlaylistCommand* command)
{
    checkForNoActiveUserError();
    Song* song = findSongByID(command->getSongID());
    checkIfSongIsInSystem(song);
    loggedInUser->addSongToPlaylist(command->getPlaylistID(), song);
}

void Utunes::deleteSongFromPlaylist(DeleteSongFrPlaylistCommand* command)
{
    checkForNoActiveUserError();
    Song* song = findSongByID(command->getSongID());
    checkIfSongIsInSystem(song);
    loggedInUser->deleteSongFromPlaylist(command->getPlaylistID(), song);
}

void Utunes::printPlaylistSongs(GetPlaylistCommand* command)
{
    checkForNoActiveUserError();
    Playlist* playlist;
    int id = command->getID();
    for(User* user:users)
    {
        playlist = user->getPlaylist(id);
        if(playlist != nullptr)
        {
            print(playlist);
            return;
        }
    }
    playlistNotInSystemError();
}

void Utunes::playlistNotInSystemError()
{
    exception* ex = new NotFoundError();
    throw ex;
}

void Utunes::printAllPlaylists(GetAllPlaylistsCommand* command)
{
    checkForNoActiveUserError(); 
    User* user = findUserByUsername(command->getUsername());
    checkIfUserIsInSystem(user);
    print(user->printAllPlaylists());
}

void Utunes::addCommentToSong(AddCommentCommand* command)
{
    checkForNoActiveUserError();
    Song* song = findSongByID(command->getSongID());
    checkIfSongIsInSystem(song);
    song->addComment(command->getTime(), command->getComment(), loggedInUser->getUsername());   
}

void Utunes::printComments(GetCommentsCommand* command)
{
    checkForNoActiveUserError();
    Song* song = findSongByID(command->getID());
    checkIfSongIsInSystem(song);
    print(song->printAllComments());
}

void Utunes::addNewFilter(NewFilterCommand* command)
{
    checkForNoActiveUserError();
    SongFilter* filter = FilterManager(command).getFilter();
    filters.push_back(filter);
}

void Utunes::deleteFilters()
{
    checkForNoActiveUserError();
    for(SongFilter* filter:filters)
    {
        delete filter;
    }
    filters.clear();
}

vector<Song*> Utunes::applyFilters()
{
    vector<Song*> songs = allSongs;
    for(SongFilter* filter:filters)
    {
        songs = filter->meetCriteria(songs);
    }
    return songs;
}

void Utunes::printUsers(GetUsersCommand* command)
{
    checkForNoActiveUserError();
    checkForNoOtherUserError();
    sort(users.begin(), users.end(), UserComparator());
    for(User* user:users)
    {
        string username = user->getUsername();
        if(username != loggedInUser->getUsername())
        {
            print(username + NEXT_LINE);
        }
    }
}

void Utunes::checkForNoOtherUserError()
{
    if(users.size() == 1)
    {
        exception* ex = new EmptyError();
        throw ex;
    }
}
