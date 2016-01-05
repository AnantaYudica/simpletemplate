/*
 * Parameter.h
 *
 *  Created on: 4 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_H_
#define MASTER_TYPEHELPER_PARAMETER_H_

#include <cstddef>
#include "Parameter/Expand.h"
#include "Parameter/Values.h"
#include "Properties.h"

struct Parameter{

	template <size_t SIZE_FIRST_LEVEL = typehelper::Property::Parameter::SIZE_FIRST_LEVEL,
			size_t SIZE_SECOND_LEVEL = typehelper::Property::Parameter::SIZE_SECOND_LEVEL,
			size_t SIZE_THIRD_LEVEL = typehelper::Property::Parameter::SIZE_THIRD_LEVEL>
	struct Expand : public typehelper_parameter::Expand<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL>{

	};
	template <typename T, T ... VAL>
	struct Values : public typehelper_parameter::Values<T, VAL ...> {

	};
};


#endif /* MASTER_TYPEHELPER_PARAMETER_H_ */
