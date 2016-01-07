/*
 * Parameter.h
 *
 *  Created on: 4 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_H_
#define MASTER_TYPEHELPER_PARAMETER_H_

#include <cstddef>
#include "parameter/Values.h"
#include "parameter/Properties.h"
#include "parameter/Expand.h"

namespace typehelper {

class parameter{
private:
	parameter() {};
public:
	template <typename T, T ... VAL>
	class Values : public typehelper_parameter::Values<T, VAL ...> {
	private:
		Values() {};
	};

	class values : public typehelper_parameter::values {
	private:
		values() {};
	};


	template <size_t SIZE_FIRST_LEVEL = typehelper_parameter::Property::Expand::SIZE_FIRST_LEVEL,
		size_t SIZE_SECOND_LEVEL = typehelper_parameter::Property::Expand::SIZE_SECOND_LEVEL,
		size_t SIZE_THIRD_LEVEL = typehelper_parameter::Property::Expand::SIZE_THIRD_LEVEL>
	class Expand : public typehelper_parameter::Expand<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL>{
	private:
		Expand() {};
	};
};

};

#endif /* MASTER_TYPEHELPER_PARAMETER_H_ */
