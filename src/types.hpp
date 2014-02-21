#ifndef TYPES_HPP
#define TYPES_HPP
#include <string>
#include <utility>

typedef std::string State;
/**
 * @brief A pair<sequence, score> representing a whole playout til the end of game.
 *
 */
typedef std::pair<State, int> Playout;
typedef char Move;

#endif