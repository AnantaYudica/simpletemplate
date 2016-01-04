/*
 * Expand.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_EXPAND_H_
#define MASTER_TYPEHELPER_PARAMETER_EXPAND_H_

#include "Properties.h"
#include "Values.h"
#include "Expand/Levels.h"

template <size_t SIZE_FIRST_LEVEL = typehelper_Parameter_Properties::Property::SIZE_FIRST_LEVEL,
	size_t SIZE_SECOND_LEVEL = typehelper_Parameter_Properties::Property::SIZE_SECOND_LEVEL,
	size_t SIZE_THIRD_LEVEL = typehelper_Parameter_Properties::Property::SIZE_THIRD_LEVEL>
class Expand {
private:
	static const size_t MAXIMUM_LIMIT_FIRST_LEVEL = SIZE_FIRST_LEVEL;
	static const size_t MAXIMUM_LIMIT_SECOND_LEVEL = SIZE_FIRST_LEVEL;
	static const size_t MAXIMUM_LIMIT_THIRD_LEVEL = SIZE_THIRD_LEVEL;

public:
	template <class Tv, class Ti,
		Tv (*BODY_FUNCTION)(Tv, Ti, size_t),
		bool (*CONDITION_FUNCTION)(Tv, Ti, size_t),
		Ti (*AFTERTHOUGHT_FUNCTION)(Ti, size_t),
		Tv START_VALUE = 0, Ti START_AFTERTHOUGHT = 0>
	struct values {
		typedef typename Levels<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL,
				Tv, Ti, BODY_FUNCTION, CONDITION_FUNCTION, AFTERTHOUGHT_FUNCTION, START_VALUE, START_AFTERTHOUGHT>::result::values result;
	};
};

#endif /* MASTER_TYPEHELPER_PARAMETER_EXPAND_H_ */
