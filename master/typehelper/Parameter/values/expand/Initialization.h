/*
 * Initialization.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_VALUES_EXPAND_INITIALIZATION_H_
#define MASTER_TYPEHELPER_PARAMETER_VALUES_EXPAND_INITIALIZATION_H_

#include <cstddef>

template <class Tv, class Ti,
	Tv (*BODY_FUNCTION)(Tv, Ti, size_t),
	bool (*CONDITION_FUNCTION)(Tv, Ti, size_t),
	Ti (*AFTERTHOUGHT_FUNCTION)(Ti, size_t)>
struct Initialization {
	constexpr static Tv (*body_function)(Tv, Ti, size_t) = BODY_FUNCTION;
	constexpr static bool (*condition_function)(Tv, Ti, size_t) = CONDITION_FUNCTION;
	constexpr static Ti (*afterthought_function)(Ti, size_t) = AFTERTHOUGHT_FUNCTION;
};

#endif /* MASTER_TYPEHELPER_PARAMETER_VALUES_EXPAND_INITIALIZATION_H_ */
