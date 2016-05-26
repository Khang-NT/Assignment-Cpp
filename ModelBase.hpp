/*
 * ModelBase.h
 *
 *  Created on: May 25, 2016
 *      Author: khang
 */

#ifndef MODELBASE_HPP_
#define MODELBASE_HPP_

#include "json.hpp"

using json = nlohmann::json;

class ModelBase {
public:
	ModelBase() {};
	/**
	 * Create instance from json data
	 * @param data
	 */
	virtual ModelBase(json data);
	virtual json toJson();
	virtual ~ModelBase() {};
};

#endif /* MODELBASE_HPP_ */
