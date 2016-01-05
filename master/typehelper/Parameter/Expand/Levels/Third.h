/*
 * Third.h
 *
 *  Created on: 3 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_THIRD_H_
#define MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_THIRD_H_

#include "../Properties.h"
#include "../Variable.h"
#include "../Status.h"
#include "../Result.h"
#include "Second.h"
#include "../../Values.h"


using namespace typehelper_Parameter_Expand_Properities;

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	int STATUS_CODE, typename VARIABLE, typename INITIALIZATION, typename VALUES>
struct Third {};

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	typename VARIABLE, typename INITIALIZATION, typename VALUES>
struct Third<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
	Property::STATUS_CODE_RUN, VARIABLE, INITIALIZATION, VALUES> {
	typedef Variable<typename VARIABLE::value_type, typename VARIABLE::afterhought_type,
			VARIABLE::value, VARIABLE::afterthought, VARIABLE::total, 0, 0,
			VARIABLE::count_third_level> push_variable;
	typedef typehelper_parameter::template Values<typename VARIABLE::value_type> push_values;
	typedef typename Second<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
			Property::STATUS_CODE_RUN, push_variable, INITIALIZATION, push_values>::result ret_result;

	constexpr static size_t total = ret_result::variable::total;
	constexpr static size_t count_first_level = ret_result::variable::count_first_level;
	constexpr static size_t count_second_level = ret_result::variable::count_second_level;
	constexpr static size_t count_third_level = VARIABLE::count_third_level + 1;

	typedef Variable<typename VARIABLE::value_type, typename VARIABLE::afterhought_type,
			ret_result::variable::value, ret_result::variable::afterthought, total,
			count_first_level, count_second_level, count_third_level> next_variable;
	constexpr static int code = Status<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
				Property::ID_THIRD_LEVEL, ret_result::code, count_third_level>::code;
	typedef typename Third<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
			code, next_variable, INITIALIZATION,
			typename VALUES::template join<typename ret_result::values>::type>::result result;
};

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	typename VARIABLE, typename INITIALIZATION, typename VALUES>
struct Third<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
	Property::STATUS_CODE_END, VARIABLE, INITIALIZATION, VALUES> {
	typedef Result<Property::STATUS_CODE_END, VARIABLE, VALUES> result;
};

template <size_t SIZE_FIRST_LEVEL, size_t SIZE_SECOND_LEVEL, size_t SIZE_THIRD_LEVEL,
	typename VARIABLE, typename INITIALIZATION, typename VALUES>
struct Third<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
	Property::STATUS_CODE_RUN_AND_BREAK_SECOND_LEVEL, VARIABLE, INITIALIZATION, VALUES> {
	typedef Result<Property::STATUS_CODE_RUN_AND_BREAK_SECOND_LEVEL, VARIABLE, VALUES> result;
};


#endif /* MASTER_TYPEHELPER_PARAMETER_EXPAND_LEVELS_THIRD_H_ */
