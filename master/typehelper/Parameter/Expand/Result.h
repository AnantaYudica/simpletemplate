/*
 * Result.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_EXPAND_RESULT_H_
#define MASTER_TYPEHELPER_PARAMETER_EXPAND_RESULT_H_

#include "Properties.h"

template <int STATUS_CODE, typename VARIABLE, typename  VALUES>
struct Result {
	constexpr static int code = STATUS_CODE;
	typedef VARIABLE variable;
	typedef VALUES values;
};


#endif /* MASTER_TYPEHELPER_PARAMETER_EXPAND_RESULT_H_ */
