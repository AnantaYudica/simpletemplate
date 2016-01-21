/*
 * Values.h
 *
 *  Created on: 22 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_STORAGE_VALUES_H_
#define MASTER_TYPEHELPER_PARAMETER_STORAGE_VALUES_H_


namespace typehelper_parameter_storage {

template<typename ... ARGS>
class Values;

template<typename ARG>
class Values<ARG> {
public:
	ARG value;
	Values() {};
	Values(ARG arg) {
		value = arg;
	};
};

template<typename ARG0, typename ... ARGS>
class Values<ARG0, ARGS ...> :
	public Values<ARGS ...>{
public:
	ARG0 value;
	Values() {};
	Values(ARG0 arg0, ARGS ... args) : Values<ARGS ...>(args ...){
		value = arg0;
	};
};

};


#endif /* MASTER_TYPEHELPER_PARAMETER_STORAGE_VALUES_H_ */
