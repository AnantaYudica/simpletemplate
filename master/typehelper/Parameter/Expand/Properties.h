/*
 * Properties.h
 *
 *  Created on: 24 Des 2015
 *      Author: "Ananta Yudica"
 */

#ifndef MASTER_TYPEHELPER_PARAMETER_EXPAND_PROPERTIES_H_
#define MASTER_TYPEHELPER_PARAMETER_EXPAND_PROPERTIES_H_

namespace typehelper_Parameter_Expand_Properities {

struct Property {
	static const int ID_FIRST_LEVEL = 0;
	static const int ID_SECOND_LEVEL = 1;
	static const int ID_THIRD_LEVEL = 2;

	static const int STATUS_CODE_END = 0;
	static const int STATUS_CODE_RUN = 1;
	static const int STATUS_CODE_RUN_AND_BREAK_FIRST_LEVEL = 11;
	static const int STATUS_CODE_RUN_AND_BREAK_SECOND_LEVEL = 12;
	static const int STATUS_CODE_RUN_AND_BREAK_THIRD_LEVEL = 13;
};

};

#endif /* MASTER_TYPEHELPER_PARAMETER_EXPAND_PROPERTIES_H_ */
