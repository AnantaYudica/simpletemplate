/*
 * First.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_FIRST_H_
#define MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_FIRST_H_

#include "../../Values.h"
#include "../Properties.h"
#include "../Result.h"
#include "../Status.h"
#include "../Variable.h"

using namespace typehelper_parameter_expand;


template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	int STATUS_CODE, typename VARIABLE, typename INITIALIZATION, typename VARIABLE::value_type ... VALUES>
struct First {};

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	typename VARIABLE, typename INITIALIZATION, typename VARIABLE::value_type ... VALUES>
struct First<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
	Property::STATUS_CODE_RUN, VARIABLE, INITIALIZATION, VALUES ...> {
	constexpr static typename VARIABLE::value_type value =
			(*(INITIALIZATION::body_function))(VARIABLE::value, VARIABLE::afterthought, VARIABLE::total);
	constexpr static typename VARIABLE::afterhought_type afterthought =
			(*(INITIALIZATION::afterthought_function))(VARIABLE::afterthought, VARIABLE::total);

	constexpr static size_t count_first_level = VARIABLE::count_first_level + 1;
	constexpr static size_t count_second_level = VARIABLE::count_second_level;
	constexpr static size_t count_third_level = VARIABLE::count_third_level;
	constexpr static size_t total = VARIABLE::total + 1;
	constexpr static bool is_end =
			!(*(INITIALIZATION::condition_function))(value, afterthought, total);
	constexpr static int code = Status<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
			Property::ID_FIRST_LEVEL, Property::STATUS_CODE_RUN, count_first_level, is_end>::code;
	typedef Variable<typename VARIABLE::value_type, typename VARIABLE::afterhought_type,
			value, afterthought, total, count_first_level, count_second_level, count_third_level> variable;
	typedef typename First<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
			code, variable, INITIALIZATION, VALUES ..., VARIABLE::value>::result result;
};

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	typename VARIABLE, typename INITIALIZATION, typename VARIABLE::value_type ... VALUES>
struct First<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
	Property::STATUS_CODE_RUN_AND_BREAK_FIRST_LEVEL, VARIABLE, INITIALIZATION, VALUES ...> {
	typedef typehelper_parameter::Values<typename VARIABLE::value_type, VALUES ...> values;
	typedef Result<Property::STATUS_CODE_RUN_AND_BREAK_FIRST_LEVEL, VARIABLE, values> result;
};

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	typename VARIABLE, typename INITIALIZATION, typename VARIABLE::value_type ... VALUES>
struct First<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
	Property::STATUS_CODE_END, VARIABLE, INITIALIZATION, VALUES ...> {
	typedef typehelper_parameter::Values<typename VARIABLE::value_type, VALUES ...> values;
	typedef Result<Property::STATUS_CODE_END, VARIABLE, values> result;
};


#endif /* MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_FIRST_H_ */
