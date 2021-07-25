#ifndef _COMMAND_MANAGER_HPP_
#define _COMMAND_MANAGER_HPP_ 1

#include "UtunesCommand.hpp"
#include "WriteRequest.hpp"
#include "ReadRequest.hpp"
#include "DeleteRequest.hpp"
#include "GetAllSongsCommand.hpp"
#include "GetSongCommand.hpp"
#include "LoginCommand.hpp"
#include "LogoutCommand.hpp"
#include "SignupCommand.hpp"
#include "CommandParser.hpp"
#include "AddLikeCommand.hpp"
#include "DeleteLikeCommand.hpp"
#include "GetLikesCommand.hpp"
#include "NewPlaylistCommand.hpp"
#include "AddSongToPlaylistCommand.hpp"
#include "DeleteSongFrPlaylistCommand.hpp"
#include "GetPlaylistCommand.hpp"
#include "GetAllPlaylistsCommand.hpp"
#include "AddCommentCommand.hpp"
#include "GetCommentsCommand.hpp"
#include "LikesFilterCommand.hpp"
#include "ReleaseYearFilterCommand.hpp"
#include "DeleteFiltersCommand.hpp"
#include "ArtistFilterCommand.hpp"
#include "GetSimilarUsersCommand.hpp"
#include "GetRecommendedSongsCommand.hpp"
#include "../ExceptionClass/BadRequestError.hpp"
#include "../ExceptionClass/NotFoundError.hpp"
#include "GetUsersCommand.hpp"

class CommandManager
{
public:
    CommandManager(const std::string& originalCommand);
    ~CommandManager();
    UtunesCommand* getCommand();
private:
    UtunesCommand* command;
    std::string input;

    void parse();
    void parseWriteRequest(const InputLine& inputLine);
    void parseReadRequest(const InputLine& inputLine);
    void parseDeleteRequest(const InputLine& inputLine);
    void badRequestError();
    void notFoundError();
    void parseNewFilterRequest(const InputLine& inputLine);
};



#endif