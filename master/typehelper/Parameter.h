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
};

};

#endif /* MASTER_TYPEHELPER_PARAMETER_H_ */
