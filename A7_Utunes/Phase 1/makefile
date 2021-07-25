CC := g++ -std=c++11 -g
BUILD_DIR = build
EXCEPTION_DIR = ExceptionClass
COMMAND_DIR = CommandClass
SONG_FILTER_DIR = SongFilterClass

.PHONY: all
all: makedir utunes.out

utunes.out: $(BUILD_DIR)/User.o $(BUILD_DIR)/Song.o $(BUILD_DIR)/SongComment.o $(BUILD_DIR)/CSVLineParser.o $(BUILD_DIR)/Playlist.o $(BUILD_DIR)/CSVParser.o $(BUILD_DIR)/Utunes.o $(BUILD_DIR)/InputLine.o $(BUILD_DIR)/CommandParser.o $(BUILD_DIR)/BadRequestError.o $(BUILD_DIR)/NotFoundError.o $(BUILD_DIR)/PermissionDeniedError.o $(BUILD_DIR)/EmptyError.o $(BUILD_DIR)/CommandManager.o $(BUILD_DIR)/UtunesCommand.o $(BUILD_DIR)/ReadRequest.o $(BUILD_DIR)/WriteRequest.o $(BUILD_DIR)/DeleteRequest.o $(BUILD_DIR)/LoginCommand.o $(BUILD_DIR)/LogoutCommand.o $(BUILD_DIR)/SignupCommand.o $(BUILD_DIR)/GetSongCommand.o $(BUILD_DIR)/GetAllSongsCommand.o $(BUILD_DIR)/AddLikeCommand.o $(BUILD_DIR)/GetLikesCommand.o $(BUILD_DIR)/DeleteLikeCommand.o $(BUILD_DIR)/DeleteSongFrPlaylistCommand.o $(BUILD_DIR)/NewPlaylistCommand.o $(BUILD_DIR)/AddSongToPlaylistCommand.o $(BUILD_DIR)/GetAllPlaylistsCommand.o $(BUILD_DIR)/GetPlaylistCommand.o $(BUILD_DIR)/GetCommentsCommand.o $(BUILD_DIR)/AddCommentCommand.o $(BUILD_DIR)/NewFilterCommand.o $(BUILD_DIR)/ArtistFilterCommand.o $(BUILD_DIR)/LikesFilterCommand.o $(BUILD_DIR)/ReleaseYearFilterCommand.o $(BUILD_DIR)/ReleaseYearCriteria.o $(BUILD_DIR)/NumberOfLikesCriteria.o $(BUILD_DIR)/ArtistCriteria.o $(BUILD_DIR)/SongFilter.o $(BUILD_DIR)/FilterManager.o $(BUILD_DIR)/DeleteFiltersCommand.o $(BUILD_DIR)/GetUsersCommand.o $(BUILD_DIR)/main.o
	$(CC) $(BUILD_DIR)/User.o $(BUILD_DIR)/Song.o $(BUILD_DIR)/SongComment.o $(BUILD_DIR)/CSVLineParser.o $(BUILD_DIR)/Playlist.o $(BUILD_DIR)/CSVParser.o $(BUILD_DIR)/Utunes.o $(BUILD_DIR)/InputLine.o $(BUILD_DIR)/CommandParser.o $(BUILD_DIR)/BadRequestError.o $(BUILD_DIR)/NotFoundError.o $(BUILD_DIR)/PermissionDeniedError.o $(BUILD_DIR)/EmptyError.o $(BUILD_DIR)/CommandManager.o $(BUILD_DIR)/UtunesCommand.o $(BUILD_DIR)/ReadRequest.o $(BUILD_DIR)/WriteRequest.o $(BUILD_DIR)/DeleteRequest.o $(BUILD_DIR)/LoginCommand.o $(BUILD_DIR)/LogoutCommand.o $(BUILD_DIR)/SignupCommand.o $(BUILD_DIR)/GetSongCommand.o $(BUILD_DIR)/GetAllSongsCommand.o $(BUILD_DIR)/AddLikeCommand.o $(BUILD_DIR)/GetLikesCommand.o $(BUILD_DIR)/DeleteLikeCommand.o $(BUILD_DIR)/DeleteSongFrPlaylistCommand.o $(BUILD_DIR)/NewPlaylistCommand.o $(BUILD_DIR)/AddSongToPlaylistCommand.o $(BUILD_DIR)/GetAllPlaylistsCommand.o $(BUILD_DIR)/GetPlaylistCommand.o $(BUILD_DIR)/GetCommentsCommand.o $(BUILD_DIR)/AddCommentCommand.o $(BUILD_DIR)/NewFilterCommand.o $(BUILD_DIR)/ArtistFilterCommand.o $(BUILD_DIR)/LikesFilterCommand.o $(BUILD_DIR)/ReleaseYearFilterCommand.o $(BUILD_DIR)/ReleaseYearCriteria.o $(BUILD_DIR)/NumberOfLikesCriteria.o $(BUILD_DIR)/ArtistCriteria.o $(BUILD_DIR)/SongFilter.o $(BUILD_DIR)/FilterManager.o $(BUILD_DIR)/DeleteFiltersCommand.o $(BUILD_DIR)/GetUsersCommand.o $(BUILD_DIR)/main.o -o utunes.out

$(BUILD_DIR)/main.o: main.cpp Utunes.hpp Song.hpp User.hpp SongComment.hpp Playlist.hpp CSVLineParser.hpp CSVParser.hpp InputLine.hpp $(EXCEPTION_DIR)/BadRequestError.hpp $(EXCEPTION_DIR)/NotFoundError.hpp $(EXCEPTION_DIR)/PermissionDeniedError.hpp $(EXCEPTION_DIR)/EmptyError.hpp $(COMMAND_DIR)/CommandParser.hpp $(COMMAND_DIR)/CommandManager.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/DeleteRequest.hpp $(COMMAND_DIR)/LoginCommand.hpp $(COMMAND_DIR)/LogoutCommand.hpp $(COMMAND_DIR)/SignupCommand.hpp $(COMMAND_DIR)/GetSongCommand.hpp $(COMMAND_DIR)/GetAllSongsCommand.hpp $(COMMAND_DIR)/DeleteLikeCommand.hpp $(COMMAND_DIR)/GetLikesCommand.hpp $(COMMAND_DIR)/AddLikeCommand.hpp $(COMMAND_DIR)/DeleteSongFrPlaylistCommand.hpp $(COMMAND_DIR)/NewPlaylistCommand.hpp $(COMMAND_DIR)/AddSongToPlaylistCommand.hpp $(COMMAND_DIR)/GetAllPlaylistsCommand.hpp $(COMMAND_DIR)/GetPlaylistCommand.hpp $(COMMAND_DIR)/GetCommentsCommand.hpp $(COMMAND_DIR)/AddCommentCommand.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/ArtistFilterCommand.hpp $(COMMAND_DIR)/LikesFilterCommand.hpp $(COMMAND_DIR)/ReleaseYearFilterCommand.hpp $(SONG_FILTER_DIR)/ReleaseYearCriteria.hpp $(SONG_FILTER_DIR)/NumberOfLikesCriteria.hpp $(SONG_FILTER_DIR)/ArtistCriteria.hpp $(SONG_FILTER_DIR)/SongFilter.hpp $(SONG_FILTER_DIR)/FilterManager.hpp $(COMMAND_DIR)/DeleteFiltersCommand.hpp $(COMMAND_DIR)/GetUsersCommand.hpp
	$(CC) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Utunes.o: Utunes.hpp Utunes.cpp Song.hpp SongComment.hpp User.hpp Playlist.hpp CSVLineParser.hpp CSVParser.hpp InputLine.hpp $(COMMAND_DIR)/CommandParser.hpp $(EXCEPTION_DIR)/BadRequestError.hpp $(EXCEPTION_DIR)/NotFoundError.hpp $(EXCEPTION_DIR)/PermissionDeniedError.hpp $(EXCEPTION_DIR)/EmptyError.hpp $(COMMAND_DIR)/CommandManager.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/DeleteRequest.hpp $(COMMAND_DIR)/LoginCommand.hpp $(COMMAND_DIR)/LogoutCommand.hpp $(COMMAND_DIR)/SignupCommand.hpp $(COMMAND_DIR)/GetSongCommand.hpp $(COMMAND_DIR)/GetAllSongsCommand.hpp $(COMMAND_DIR)/DeleteLikeCommand.hpp $(COMMAND_DIR)/GetLikesCommand.hpp $(COMMAND_DIR)/AddLikeCommand.hpp $(COMMAND_DIR)/DeleteSongFrPlaylistCommand.hpp $(COMMAND_DIR)/NewPlaylistCommand.hpp $(COMMAND_DIR)/AddSongToPlaylistCommand.hpp $(COMMAND_DIR)/GetAllPlaylistsCommand.hpp $(COMMAND_DIR)/GetPlaylistCommand.hpp $(COMMAND_DIR)/GetCommentsCommand.hpp $(COMMAND_DIR)/AddCommentCommand.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/ArtistFilterCommand.hpp $(COMMAND_DIR)/LikesFilterCommand.hpp $(COMMAND_DIR)/ReleaseYearFilterCommand.hpp $(SONG_FILTER_DIR)/ReleaseYearCriteria.hpp $(SONG_FILTER_DIR)/NumberOfLikesCriteria.hpp $(SONG_FILTER_DIR)/ArtistCriteria.hpp $(SONG_FILTER_DIR)/SongFilter.hpp $(SONG_FILTER_DIR)/FilterManager.hpp $(COMMAND_DIR)/DeleteFiltersCommand.hpp $(COMMAND_DIR)/GetUsersCommand.hpp
	$(CC) -c Utunes.cpp -o $(BUILD_DIR)/Utunes.o

$(BUILD_DIR)/User.o: User.hpp User.cpp Playlist.hpp Song.hpp $(EXCEPTION_DIR)/BadRequestError.hpp $(EXCEPTION_DIR)/NotFoundError.hpp $(EXCEPTION_DIR)/PermissionDeniedError.hpp $(EXCEPTION_DIR)/EmptyError.hpp SongComment.hpp
	$(CC) -c User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Playlist.o: Playlist.cpp Playlist.hpp Song.hpp SongComment.hpp $(EXCEPTION_DIR)/BadRequestError.hpp $(EXCEPTION_DIR)/EmptyError.hpp
	$(CC) -c Playlist.cpp -o $(BUILD_DIR)/Playlist.o

$(BUILD_DIR)/Song.o: Song.hpp Song.cpp SongComment.hpp $(EXCEPTION_DIR)/EmptyError.hpp
	$(CC) -c Song.cpp -o $(BUILD_DIR)/Song.o

$(BUILD_DIR)/SongComment.o: SongComment.cpp SongComment.hpp
	$(CC) -c SongComment.cpp -o $(BUILD_DIR)/SongComment.o

$(BUILD_DIR)/CSVLineParser.o: CSVLineParser.hpp CSVLineParser.cpp InputLine.hpp
	$(CC) -c CSVLineParser.cpp -o $(BUILD_DIR)/CSVLineParser.o

$(BUILD_DIR)/CSVParser.o: CSVParser.hpp CSVParser.cpp InputLine.hpp
	$(CC) -c CSVParser.cpp -o $(BUILD_DIR)/CSVParser.o

$(BUILD_DIR)/InputLine.o: InputLine.hpp InputLine.cpp
	$(CC) -c InputLine.cpp -o $(BUILD_DIR)/InputLine.o

$(BUILD_DIR)/BadRequestError.o: $(EXCEPTION_DIR)/BadRequestError.hpp $(EXCEPTION_DIR)/BadRequestError.cpp
	$(CC) -c $(EXCEPTION_DIR)/BadRequestError.cpp -o $(BUILD_DIR)/BadRequestError.o

$(BUILD_DIR)/NotFoundError.o: $(EXCEPTION_DIR)/NotFoundError.hpp $(EXCEPTION_DIR)/NotFoundError.cpp
	$(CC) -c $(EXCEPTION_DIR)/NotFoundError.cpp -o $(BUILD_DIR)/NotFoundError.o

$(BUILD_DIR)/PermissionDeniedError.o: $(EXCEPTION_DIR)/PermissionDeniedError.hpp $(EXCEPTION_DIR)/PermissionDeniedError.cpp
	$(CC) -c $(EXCEPTION_DIR)/PermissionDeniedError.cpp -o $(BUILD_DIR)/PermissionDeniedError.o

$(BUILD_DIR)/EmptyError.o: $(EXCEPTION_DIR)/EmptyError.hpp $(EXCEPTION_DIR)/EmptyError.cpp
	$(CC) -c $(EXCEPTION_DIR)/EmptyError.cpp -o $(BUILD_DIR)/EmptyError.o

$(BUILD_DIR)/CommandParser.o: $(COMMAND_DIR)/CommandParser.hpp $(COMMAND_DIR)/CommandParser.cpp InputLine.hpp
	$(CC) -c $(COMMAND_DIR)/CommandParser.cpp -o $(BUILD_DIR)/CommandParser.o

$(BUILD_DIR)/UtunesCommand.o: $(COMMAND_DIR)/UtunesCommand.cpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/UtunesCommand.cpp -o $(BUILD_DIR)/UtunesCommand.o

$(BUILD_DIR)/WriteRequest.o: $(COMMAND_DIR)/WriteRequest.cpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/WriteRequest.cpp -o $(BUILD_DIR)/WriteRequest.o

$(BUILD_DIR)/ReadRequest.o: $(COMMAND_DIR)/ReadRequest.cpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/ReadRequest.cpp -o $(BUILD_DIR)/ReadRequest.o

$(BUILD_DIR)/DeleteRequest.o: $(COMMAND_DIR)/DeleteRequest.cpp $(COMMAND_DIR)/DeleteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/DeleteRequest.cpp -o $(BUILD_DIR)/DeleteRequest.o

$(BUILD_DIR)/LoginCommand.o: $(COMMAND_DIR)/LoginCommand.cpp $(COMMAND_DIR)/LoginCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/LoginCommand.cpp -o $(BUILD_DIR)/LoginCommand.o

$(BUILD_DIR)/SignupCommand.o: $(COMMAND_DIR)/SignupCommand.cpp $(COMMAND_DIR)/SignupCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/SignupCommand.cpp -o $(BUILD_DIR)/SignupCommand.o

$(BUILD_DIR)/LogoutCommand.o: $(COMMAND_DIR)/LogoutCommand.cpp $(COMMAND_DIR)/LogoutCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/LogoutCommand.cpp -o $(BUILD_DIR)/LogoutCommand.o

$(BUILD_DIR)/GetSongCommand.o: $(COMMAND_DIR)/GetSongCommand.cpp $(COMMAND_DIR)/GetSongCommand.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/GetSongCommand.cpp -o $(BUILD_DIR)/GetSongCommand.o

$(BUILD_DIR)/GetAllSongsCommand.o: $(COMMAND_DIR)/GetAllSongsCommand.cpp $(COMMAND_DIR)/GetAllSongsCommand.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/GetAllSongsCommand.cpp -o $(BUILD_DIR)/GetAllSongsCommand.o

$(BUILD_DIR)/CommandManager.o: $(COMMAND_DIR)/CommandManager.cpp $(COMMAND_DIR)/CommandManager.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/DeleteRequest.hpp $(COMMAND_DIR)/LoginCommand.hpp $(COMMAND_DIR)/LogoutCommand.hpp $(COMMAND_DIR)/SignupCommand.hpp $(COMMAND_DIR)/GetSongCommand.hpp $(COMMAND_DIR)/GetAllSongsCommand.hpp $(COMMAND_DIR)/DeleteLikeCommand.hpp $(COMMAND_DIR)/GetLikesCommand.hpp $(COMMAND_DIR)/AddLikeCommand.hpp $(COMMAND_DIR)/DeleteSongFrPlaylistCommand.hpp $(COMMAND_DIR)/NewPlaylistCommand.hpp $(COMMAND_DIR)/AddSongToPlaylistCommand.hpp $(COMMAND_DIR)/GetAllPlaylistsCommand.hpp $(COMMAND_DIR)/GetPlaylistCommand.hpp $(COMMAND_DIR)/GetCommentsCommand.hpp $(COMMAND_DIR)/AddCommentCommand.hpp $(EXCEPTION_DIR)/NotFoundError.hpp $(EXCEPTION_DIR)/BadRequestError.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/ArtistFilterCommand.hpp $(COMMAND_DIR)/LikesFilterCommand.hpp $(COMMAND_DIR)/ReleaseYearFilterCommand.hpp $(COMMAND_DIR)/GetUsersCommand.hpp
	$(CC) -c $(COMMAND_DIR)/CommandManager.cpp -o $(BUILD_DIR)/CommandManager.o

$(BUILD_DIR)/GetLikesCommand.o: $(COMMAND_DIR)/GetLikesCommand.cpp $(COMMAND_DIR)/GetLikesCommand.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/GetLikesCommand.cpp -o $(BUILD_DIR)/GetLikesCommand.o

$(BUILD_DIR)/AddLikeCommand.o: $(COMMAND_DIR)/AddLikeCommand.cpp $(COMMAND_DIR)/AddLikeCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/AddLikeCommand.cpp -o $(BUILD_DIR)/AddLikeCommand.o

$(BUILD_DIR)/DeleteLikeCommand.o: $(COMMAND_DIR)/DeleteLikeCommand.cpp $(COMMAND_DIR)/DeleteLikeCommand.hpp $(COMMAND_DIR)/DeleteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/DeleteLikeCommand.cpp -o $(BUILD_DIR)/DeleteLikeCommand.o	

$(BUILD_DIR)/GetPlaylistCommand.o: $(COMMAND_DIR)/GetPlaylistCommand.cpp $(COMMAND_DIR)/GetPlaylistCommand.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/GetPlaylistCommand.cpp -o $(BUILD_DIR)/GetPlaylistCommand.o

$(BUILD_DIR)/GetAllPlaylistsCommand.o: $(COMMAND_DIR)/GetAllPlaylistsCommand.cpp $(COMMAND_DIR)/GetAllPlaylistsCommand.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/GetAllPlaylistsCommand.cpp -o $(BUILD_DIR)/GetAllPlaylistsCommand.o

$(BUILD_DIR)/AddSongToPlaylistCommand.o: $(COMMAND_DIR)/AddSongToPlaylistCommand.cpp $(COMMAND_DIR)/AddSongToPlaylistCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/AddSongToPlaylistCommand.cpp -o $(BUILD_DIR)/AddSongToPlaylistCommand.o

$(BUILD_DIR)/NewPlaylistCommand.o: $(COMMAND_DIR)/NewPlaylistCommand.cpp $(COMMAND_DIR)/NewPlaylistCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/NewPlaylistCommand.cpp -o $(BUILD_DIR)/NewPlaylistCommand.o

$(BUILD_DIR)/DeleteSongFrPlaylistCommand.o: $(COMMAND_DIR)/DeleteSongFrPlaylistCommand.cpp $(COMMAND_DIR)/DeleteSongFrPlaylistCommand.hpp $(COMMAND_DIR)/DeleteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/DeleteSongFrPlaylistCommand.cpp -o $(BUILD_DIR)/DeleteSongFrPlaylistCommand.o		

$(BUILD_DIR)/AddCommentCommand.o: $(COMMAND_DIR)/AddCommentCommand.cpp $(COMMAND_DIR)/AddCommentCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/AddCommentCommand.cpp -o $(BUILD_DIR)/AddCommentCommand.o

$(BUILD_DIR)/GetCommentsCommand.o: $(COMMAND_DIR)/GetCommentsCommand.cpp $(COMMAND_DIR)/GetCommentsCommand.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/GetCommentsCommand.cpp -o $(BUILD_DIR)/GetCommentsCommand.o

$(BUILD_DIR)/NewFilterCommand.o: $(COMMAND_DIR)/NewFilterCommand.cpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/NewFilterCommand.cpp -o $(BUILD_DIR)/NewFilterCommand.o

$(BUILD_DIR)/ArtistFilterCommand.o: $(COMMAND_DIR)/ArtistFilterCommand.cpp $(COMMAND_DIR)/ArtistFilterCommand.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/ArtistFilterCommand.cpp -o $(BUILD_DIR)/ArtistFilterCommand.o

$(BUILD_DIR)/LikesFilterCommand.o: $(COMMAND_DIR)/LikesFilterCommand.cpp $(COMMAND_DIR)/LikesFilterCommand.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/BadRequestError.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/LikesFilterCommand.cpp -o $(BUILD_DIR)/LikesFilterCommand.o

$(BUILD_DIR)/DeleteFiltersCommand.o: $(COMMAND_DIR)/DeleteFiltersCommand.cpp $(COMMAND_DIR)/DeleteFiltersCommand.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/DeleteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/DeleteFiltersCommand.cpp -o $(BUILD_DIR)/DeleteFiltersCommand.o	

$(BUILD_DIR)/ReleaseYearFilterCommand.o: $(COMMAND_DIR)/ReleaseYearFilterCommand.cpp $(COMMAND_DIR)/ReleaseYearFilterCommand.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/BadRequestError.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/ReleaseYearFilterCommand.cpp -o $(BUILD_DIR)/ReleaseYearFilterCommand.o

$(BUILD_DIR)/GetUsersCommand.o: $(COMMAND_DIR)/GetUsersCommand.cpp $(COMMAND_DIR)/GetUsersCommand.hpp $(COMMAND_DIR)/ReadRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(EXCEPTION_DIR)/NotFoundError.hpp
	$(CC) -c $(COMMAND_DIR)/GetUsersCommand.cpp -o $(BUILD_DIR)/GetUsersCommand.o

$(BUILD_DIR)/SongFilter.o: $(SONG_FILTER_DIR)/SongFilter.cpp $(SONG_FILTER_DIR)/SongFilter.hpp Song.hpp SongComment.hpp $(EXCEPTION_DIR)/EmptyError.hpp
	$(CC) -c $(SONG_FILTER_DIR)/SongFilter.cpp -o $(BUILD_DIR)/SongFilter.o

$(BUILD_DIR)/ArtistCriteria.o: $(SONG_FILTER_DIR)/ArtistCriteria.cpp $(SONG_FILTER_DIR)/ArtistCriteria.hpp $(SONG_FILTER_DIR)/SongFilter.hpp Song.hpp SongComment.hpp $(EXCEPTION_DIR)/EmptyError.hpp
	$(CC) -c $(SONG_FILTER_DIR)/ArtistCriteria.cpp -o $(BUILD_DIR)/ArtistCriteria.o

$(BUILD_DIR)/NumberOfLikesCriteria.o: $(SONG_FILTER_DIR)/NumberOfLikesCriteria.cpp $(SONG_FILTER_DIR)/NumberOfLikesCriteria.hpp $(SONG_FILTER_DIR)/SongFilter.hpp Song.hpp SongComment.hpp $(EXCEPTION_DIR)/EmptyError.hpp
	$(CC) -c $(SONG_FILTER_DIR)/NumberOfLikesCriteria.cpp -o $(BUILD_DIR)/NumberOfLikesCriteria.o

$(BUILD_DIR)/ReleaseYearCriteria.o: $(SONG_FILTER_DIR)/ReleaseYearCriteria.cpp $(SONG_FILTER_DIR)/ReleaseYearCriteria.hpp $(SONG_FILTER_DIR)/SongFilter.hpp Song.hpp SongComment.hpp $(EXCEPTION_DIR)/EmptyError.hpp
	$(CC) -c $(SONG_FILTER_DIR)/ReleaseYearCriteria.cpp -o $(BUILD_DIR)/ReleaseYearCriteria.o

$(BUILD_DIR)/FilterManager.o: $(SONG_FILTER_DIR)/FilterManager.cpp $(SONG_FILTER_DIR)/FilterManager.hpp $(COMMAND_DIR)/NewFilterCommand.hpp $(COMMAND_DIR)/ArtistFilterCommand.hpp $(COMMAND_DIR)/LikesFilterCommand.hpp $(COMMAND_DIR)/ReleaseYearFilterCommand.hpp $(COMMAND_DIR)/WriteRequest.hpp $(COMMAND_DIR)/UtunesCommand.hpp $(COMMAND_DIR)/CommandEnums.hpp InputLine.hpp $(SONG_FILTER_DIR)/ReleaseYearCriteria.hpp $(SONG_FILTER_DIR)/NumberOfLikesCriteria.hpp $(SONG_FILTER_DIR)/ArtistCriteria.hpp $(SONG_FILTER_DIR)/SongFilter.hpp Song.hpp SongComment.hpp $(EXCEPTION_DIR)/EmptyError.hpp
	$(CC) -c $(SONG_FILTER_DIR)/FilterManager.cpp -o $(BUILD_DIR)/FilterManager.o


makedir: 
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean: 
	rm -rf $(BUILD_DIR)