/*
 * Status.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_EXPAND_STATUS_H_
#define MASTER_TYPEHELPER_PARAMETER_EXPAND_STATUS_H_

#include "Properties.h"
#include <cstddef>

using namespace typehelper_Parameter_Expand_Properities;

template <size_t LIMIT_FIRST_LEVEL, size_t LIMIT_SECOND_LEVEL, size_t LIMIT_THIRD_LEVEL,
	int ID, int CODE_STATUS, size_t COUNT, bool IS_END = false>
struct Status {};

template <size_t LIMIT_FIRST_LEVEL, size_t LIMIT_SECOND_LEVEL, size_t LIMIT_THIRD_LEVEL,
	int CODE_STATUS, size_t COUNT, bool IS_END>
struct Status<LIMIT_FIRST_LEVEL, LIMIT_SECOND_LEVEL, LIMIT_THIRD_LEVEL,
	Property::ID_FIRST_LEVEL, CODE_STATUS, COUNT, IS_END> {
	constexpr static int code = CODE_STATUS == Property::STATUS_CODE_END ? Property::STATUS_CODE_END :
			IS_END ? Property::STATUS_CODE_END :
					COUNT <= LIMIT_FIRST_LEVEL ? Property::STATUS_CODE_RUN :
							Property::STATUS_CODE_RUN_AND_BREAK_FIRST_LEVEL;
};

template <size_t LIMIT_FIRST_LEVEL, size_t LIMIT_SECOND_LEVEL, size_t LIMIT_THIRD_LEVEL,
	int CODE_STATUS, size_t COUNT, bool IS_END>
struct Status<LIMIT_FIRST_LEVEL, LIMIT_SECOND_LEVEL, LIMIT_THIRD_LEVEL,
	Property::ID_SECOND_LEVEL, CODE_STATUS, COUNT, IS_END> {
	constexpr static int code = CODE_STATUS == Property::STATUS_CODE_END ? Property::STATUS_CODE_END :
			IS_END ? Property::STATUS_CODE_END :
					COUNT <= LIMIT_SECOND_LEVEL ? Property::STATUS_CODE_RUN :
							Property::STATUS_CODE_RUN_AND_BREAK_SECOND_LEVEL;
};

template <size_t LIMIT_FIRST_LEVEL, size_t LIMIT_SECOND_LEVEL, size_t LIMIT_THIRD_LEVEL,
	int CODE_STATUS, size_t COUNT, bool IS_END>
struct Status<LIMIT_FIRST_LEVEL, LIMIT_SECOND_LEVEL, LIMIT_THIRD_LEVEL,
	Property::ID_THIRD_LEVEL, CODE_STATUS, COUNT, IS_END> {
	constexpr static int code = CODE_STATUS == Property::STATUS_CODE_END ? Property::STATUS_CODE_END :
			IS_END ? Property::STATUS_CODE_END :
					COUNT <= LIMIT_THIRD_LEVEL ? Property::STATUS_CODE_RUN :
							Property::STATUS_CODE_RUN_AND_BREAK_THIRD_LEVEL;
};

#endif /* MASTER_TYPEHELPER_PARAMETER_EXPAND_STATUS_H_ */
