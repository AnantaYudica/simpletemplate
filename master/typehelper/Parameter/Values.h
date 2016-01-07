/*
 * Values.h
 *
 *  Created on: 23 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_VALUES_H_
#define MASTER_TYPEHELPER_PARAMETER_VALUES_H_

#include <cstddef>
#include "values/Properties.h"

namespace typehelper_parameter{

template <typename T, T ... VAL>
class Values {
private:
	Values() {};
public:
	typedef T type;
	template <T ... BVAL> struct push_back {
		typedef Values<T, VAL..., BVAL...> type;
	};

	template <T ... FVAL> struct push_front {
		typedef Values<T, FVAL..., VAL...> type;
	};

	template <typename V> struct join {
		typedef typename V::template push_front<VAL...>::type type;
	};

	template <typename V> struct shift {
		typedef typename V::template push_back<VAL...>::type type;
	};

	static const T* to_array() {
		static const T data[sizeof...(VAL)] = {VAL ...};
		return data;
	};

	static const std::size_t& size() {
		static const std::size_t s = sizeof...(VAL);
		return s;
	};

};

};

#include "values/Expand.h"

namespace typehelper_parameter{

class values {
protected:
	values() {};
public:
	template <size_t SIZE_FIRST_LEVEL = typehelper_parameter_values::Property::Expand::SIZE_FIRST_LEVEL,
		size_t SIZE_SECOND_LEVEL = typehelper_parameter_values::Property::Expand::SIZE_SECOND_LEVEL,
		size_t SIZE_THIRD_LEVEL = typehelper_parameter_values::Property::Expand::SIZE_THIRD_LEVEL>
	class Expand : public typehelper_parameter_values::Expand<SIZE_FIRST_LEVEL, SIZE_SECOND_LEVEL, SIZE_THIRD_LEVEL>{

	};
};

};

#endif /* MASTER_TYPEHELPER_PARAMETER_VALUES_H_ */
