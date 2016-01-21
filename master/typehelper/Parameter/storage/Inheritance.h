/*
 * Inheritance.h
 *
 *  Created on: 20 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_STORAGE_INHERITANCE_H_
#define MASTER_TYPEHELPER_PARAMETER_STORAGE_INHERITANCE_H_


#include "Values.h"

namespace typehelper_parameter_storage{

template<typename ...>
class Inheritance;

template<typename ARG>
class Inheritance<ARG> {
public:
	typedef void head;
	typedef Values<ARG> current;
	static const bool is_end = true;
};

template<typename ARG0, typename ... ARGS>
class Inheritance<ARG0, ARGS ...> :
	public Inheritance <ARGS ...>{
public:
	typedef Inheritance <ARGS ...> head;
	typedef Values<ARG0, ARGS ...> current;
	static const bool is_end = false;
};

};

#endif /* MASTER_TYPEHELPER_PARAMETER_STORAGE_INHERITANCE_H_ */
