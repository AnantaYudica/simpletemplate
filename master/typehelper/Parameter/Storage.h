/*
 * Storage.h
 *
 *  Created on: 19 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_STORAGE_H_
#define MASTER_TYPEHELPER_PARAMETER_STORAGE_H_

#include "Types.h"
#include "storage/Inheritance.h"
#include "storage/Index.h"
#include "storage/Values.h"

namespace typehelper_parameter {

template<typename ... ARGS>
class Storage {
private:
	typehelper_parameter_storage::Values<ARGS...>* values;
	typedef typehelper_parameter_storage::Inheritance<ARGS ...> inheritance;
public:
	Storage() {
		values = new typehelper_parameter_storage::Values<ARGS...>();
	};
	Storage(ARGS ... args) {
		values = new typehelper_parameter_storage::Values<ARGS...>(args ...);
	};
	template<size_t INDEX>
	typename types::template Index<INDEX, ARGS...>::type* index() {
		return &(static_cast<typename typehelper_parameter_storage::Index<INDEX, inheritance>::type*>(values)->value);
	};
	template<size_t INDEX>
	void index(const typename types::template Index<INDEX, ARGS...>::type &set) {
		static_cast<typename typehelper_parameter_storage::Index<INDEX, inheritance>::type*>(values)->value = set;
	};
};

};

#endif /* MASTER_TYPEHELPER_PARAMETER_STORAGE_H_ */
