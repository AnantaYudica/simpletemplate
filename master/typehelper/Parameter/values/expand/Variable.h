/*
 * Variable.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_VALUES_EXPAND_VARIABLE_H_
#define MASTER_TYPEHELPER_PARAMETER_VALUES_EXPAND_VARIABLE_H_

#include <cstddef>

template <typename Tv, typename Ti, Tv VALUE, Ti AFTERTHOUGHT, size_t TOTAL,
	size_t COUNT_FIRST_LEVEL, size_t COUNT_SECOND_LEVEL, size_t COUNT_THIRD_LEVEL>
struct Variable {
	typedef Tv value_type;
	typedef Ti afterhought_type;
	constexpr static Tv value = VALUE;
	constexpr static Ti afterthought = AFTERTHOUGHT;
	constexpr static size_t total = TOTAL;
	constexpr static size_t count_first_level = COUNT_FIRST_LEVEL;
	constexpr static size_t count_second_level = COUNT_SECOND_LEVEL;
	constexpr static size_t count_third_level = COUNT_THIRD_LEVEL;
};

#endif /* MASTER_TYPEHELPER_PARAMETER_VALUES_EXPAND_VARIABLE_H_ */
