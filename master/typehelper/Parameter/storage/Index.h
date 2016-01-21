/*
 * Index.h
 *
 *  Created on: 20 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_STORAGE_INDEX_H_
#define MASTER_TYPEHELPER_PARAMETER_STORAGE_INDEX_H_

#include <type_traits>
#include "../Types.h"
#include <iostream>

namespace typehelper_parameter_storage{

template <size_t INDEX, typename INHERITANCE, typename = void>
class Index {
public:
	typedef typename INHERITANCE::current type;
};

template <typename INHERITANCE>
class Index<0, INHERITANCE, typename std::enable_if<!std::is_same<INHERITANCE, void>::value, void>::type> {
public:
	typedef typename INHERITANCE::current type;
};

template <size_t INDEX, typename INHERITANCE>
class Index<INDEX, INHERITANCE, typename std::enable_if<!std::is_same<INHERITANCE, void>::value, void>::type> :
	public Index<INDEX - 1, typename INHERITANCE::head>{

};

};


#endif /* MASTER_TYPEHELPER_PARAMETER_STORAGE_INDEX_H_ */
