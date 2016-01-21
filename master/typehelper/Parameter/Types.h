/*
 * Types.h
 *
 *  Created on: 8 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_TYPES_H_
#define MASTER_TYPEHELPER_PARAMETER_TYPES_H_

#include "types/Index.h"

template <typename ... ARGS>
class Types {
public:
	template<size_t INDEX>
	class Index : public typehelper_parameter_types::Index<INDEX, ARGS...> {};
};

struct types{
	template <size_t INDEX, typename ... ARGS>
	class Index : public typehelper_parameter_types::Index<INDEX, ARGS...> {};
};

#endif /* MASTER_TYPEHELPER_PARAMETER_TYPES_H_ */
