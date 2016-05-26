/*
 * FileIOHelper.hpp
 *
 *  Created on: May 25, 2016
 *      Author: khang
 */

#ifndef IOHELPER_HPP_
#define IOHELPER_HPP_


#include <iostream>
#include <vector>
#include "json.hpp"
#include "HashSum.hpp"
#include "ModelBase.hpp"

using namespace std;
using namespace Hash;

namespace IOHelper {
	/**
	 * Write out (@link ModelBase) array to output stream (pretty print).
	 * @param stream output stream.
	 * @param models array class implement (@link ModelBase).
	 */
	void saveToStream(ostream &stream, vector<ModelBase> models) {
		json jDataList;
		for (ModelBase model : models)
			jDataList.push_back(model.toJson());
		string jsonStringNormal = jDataList.dump();
		unsigned hashCode = hashSum(jsonStringNormal);

		json jObject = json({
			{"data", jDataList},
			{"code", hashCode}
		});
		stream << setw(4) << jObject;
	}

	/**
	 * Parse list (@link ModelBase) from stream.
	 * @param stream input stream
	 * @throw error if hash code is mismatch.
	 * @return array of (@link ModelBase)
	 */
	vector<ModelBase> readFromStream(iostream &stream) throw (const char*) {
		string dataStr = string((std::istreambuf_iterator<char>(stream)),
                (std::istreambuf_iterator<char>()));
		vector<ModelBase> result;
		json jObject = json::parse(dataStr);
		json jData = jObject["data"];
		unsigned hashCode = jObject["code"];
		if (!checkHashCode(jData.dump(), hashCode))
			throw "Hash code mismatch";
		else {
			for (auto& element : jData)
				result.push_back(ModelBase(element));
		}
		return result;
	}
}

#endif /* IOHELPER_HPP_ */
