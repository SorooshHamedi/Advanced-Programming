#ifndef _COMMAND_ENUMS_HPP_
#define _COMMAND_ENUMS_HPP_ 1

enum CommandGroup
{
    WRITE,
    READ,
    DELETE
};

enum CommandType
{
    LOGIN,
    LOGOUT,
    SIGNUP,
    GET_SONG,
    GET_SONGS,
    ADD_LIKE,
    GET_LIKES,
    DELETE_LIKE,
    NEW_PLAYLIST,
    GET_PLAYLISTS,
    GET_PLAYLIST,
    ADD_SONG_PLAYLIST,
    DELETE_SONG_PLAYLIST,
    ADD_COMMENT,
    GET_COMMENTS,
    NEW_FILTER,
    DELETE_FILTERS,
    GET_USERS,
    GET_SIMILAR_USERS,
    GET_RECOMMENDED_SONGS
};

#endif