/*
 * Levels.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_H_
#define MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_H_

#include "Levels/Third.h"
#include "Properties.h"
#include "Initialization.h"
#include "Status.h"
#include "Variable.h"
#include "../Values.h"

using namespace typehelper_Parameter_Expand_Properities;

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	class Tv, class Ti,
	Tv (*BODY_FUNCTION)(Tv, Ti, size_t),
	bool (*CONDITION_FUNCTION)(Tv, Ti, size_t),
	Ti (*AFTERTHOUGHT_FUNCTION)(Ti, size_t),
	Tv START_VALUE = 0, Ti START_AFTERTHOUGHT = 0>
struct Levels {
	constexpr static bool is_end = !(*CONDITION_FUNCTION) (START_VALUE, START_AFTERTHOUGHT, 0);
	constexpr static int code = Status<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
			Property::ID_THIRD_LEVEL, Property::STATUS_CODE_RUN, 0, is_end>::code;
	typedef Initialization<Tv, Ti, BODY_FUNCTION, CONDITION_FUNCTION, AFTERTHOUGHT_FUNCTION> initialization;
	typedef Variable<Tv, Ti, START_VALUE, START_AFTERTHOUGHT, 0, 0, 0, 0> variable;
	typedef Values<Tv> values;
	typedef typename Third<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
			code, variable, initialization, values>::result result;
};

#endif /* MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_H_ */
