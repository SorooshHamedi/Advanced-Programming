#include "CommandManager.hpp"
using namespace std;

const int COMMAND_GROUP_IDENTIFIER_INDEX = 0;
const int COMMAND_IDENTIFIER_INDEX = 1;
const int FILTER_IDENTIFIER_INDEX = 3;

const string LIKES_COMMAND = "likes";
const string PLAYLISTS_COMMAND = "playlists";
const string SONG_PLAYLISTS_COMMAND = "playlists_songs";
const string COMMENTS_COMMAND = "comments";
const string FILTERS_COMMAND = "filters";
const string USERS_COMMAND = "users";



CommandManager::CommandManager(const string& originalCommand)
{
    input = originalCommand;
    command = nullptr;
    try{
        parse();
    } catch(invalid_argument& ex){
        exception* newEx = new BadRequestError();
        throw newEx;
    }
}

CommandManager::~CommandManager()
{
    if(command != nullptr)
    {
        delete command;
    }
}

void CommandManager::parse()
{
    CommandParser parser(input);
    InputLine inputLine = parser.getParsedInput();
    if(inputLine[COMMAND_GROUP_IDENTIFIER_INDEX] == WRITE_REQUEST)
    {
        parseWriteRequest(inputLine);
    }
    else if(inputLine[COMMAND_GROUP_IDENTIFIER_INDEX] == READ_REQUEST)
    {
        parseReadRequest(inputLine);
    }
    else if(inputLine[COMMAND_GROUP_IDENTIFIER_INDEX] == DELETE_REQUEST)
    {
        parseDeleteRequest(inputLine);
    }
    else
    {
        badRequestError();
    }
}

void CommandManager::parseWriteRequest(const InputLine& inputLine)
{
    if(inputLine[COMMAND_IDENTIFIER_INDEX] == SIGNUP_COMMAND)
    {
        command = new SignupCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == LOGIN_COMMAND)
    {
        command = new LoginCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == LOGOUT_COMMAND)
    {
        command = new LogoutCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == LIKES_COMMAND)
    {
        command = new AddLikeCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == PLAYLISTS_COMMAND)
    {
        command = new NewPlaylistCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == SONG_PLAYLISTS_COMMAND)
    {
        command = new AddSongToPlaylistCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == COMMENTS_COMMAND)
    {
        command = new AddCommentCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == FILTERS_COMMAND)
    {
        parseNewFilterRequest(inputLine);
    }
    else
    {
        notFoundError();
    }
}

void CommandManager::parseReadRequest(const InputLine& inputLine)
{
    if(inputLine[COMMAND_IDENTIFIER_INDEX] == SONGS_COMMAND)
    {
        if(inputLine.size() == SONG_COMMAND_SIZE)
            command = new GetSongCommand(inputLine);
        else
            command = new GetAllSongsCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == LIKES_COMMAND)
    {
        command = new GetLikesCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == SONG_PLAYLISTS_COMMAND)
    {
        command = new GetPlaylistCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == PLAYLISTS_COMMAND)
    {
        command = new GetAllPlaylistsCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == COMMENTS_COMMAND)
    {
        command = new GetCommentsCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == USERS_COMMAND)
    {
        command = new GetUsersCommand(inputLine);
    }
    else
    {
        notFoundError();
    }
}

void CommandManager::parseDeleteRequest(const InputLine& inputLine)
{
    if(inputLine[COMMAND_IDENTIFIER_INDEX] == LIKES_COMMAND)
    {
        command = new DeleteLikeCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == SONG_PLAYLISTS_COMMAND)
    {
        command = new DeleteSongFrPlaylistCommand(inputLine);
    }
    else if(inputLine[COMMAND_IDENTIFIER_INDEX] == FILTERS_COMMAND)
    {
        command = new DeleteFiltersCommand(inputLine);
    }
    else
    {
        notFoundError();
    }
}

UtunesCommand* CommandManager::getCommand()
{
    return command;
}

void CommandManager::parseNewFilterRequest(const InputLine& inputLine)
{
    if(inputLine[FILTER_IDENTIFIER_INDEX] == LIKES_FILTER_IDENTIFIER)
    {
        command = new LikesFilterCommand(inputLine);
    }
    else if(inputLine[FILTER_IDENTIFIER_INDEX] == ARTIST_FILTER_IDENTIFIER)
    {
        command = new ArtistFilterCommand(inputLine);
    }
    else if(inputLine[FILTER_IDENTIFIER_INDEX] == RELEASE_YEAR_FILTER_IDENTIFIER)
    {
        command = new ReleaseYearFilterCommand(inputLine);
    }
    else
    {
        notFoundError();
    }
}

void CommandManager::badRequestError()
{
    exception* ex = new BadRequestError();
    throw ex;
}

void CommandManager::notFoundError()
{
    exception* ex = new NotFoundError();
    throw ex;

}