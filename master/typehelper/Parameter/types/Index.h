/*
 * Index.h
 *
 *  Created on: 19 Jan 2016
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_TYPES_INDEX_H_
#define MASTER_TYPEHELPER_PARAMETER_TYPES_INDEX_H_


namespace typehelper_parameter_types {

template <size_t INDEX ,typename ... ARGS>
class Index;

template <size_t INDEX, typename ARG0, typename ... ARGS>
class Index<INDEX, ARG0, ARGS ...> : public Index<INDEX - 1, ARGS ...>{

};

template <typename ARG0, typename ... ARGS>
class Index<0, ARG0, ARGS...> {
public:
	typedef ARG0 type;
};

}

#endif /* MASTER_TYPEHELPER_PARAMETER_TYPES_INDEX_H_ */
