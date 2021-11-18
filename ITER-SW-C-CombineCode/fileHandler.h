#ifndef FILEHANDLER_H
#define FILEHANDLER_H


#include "./cute/cute.h"
#include "./cute/cute_base.h"
#include "./cute/ide_listener.h"
#include "./cute/xml_listener.h"
#include "./cute/cute_runner.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include "./ITER_API/common_definitions.h"
#include "mat.h"
#include <math.h>

#define ASSERT_THROWS_MSG(code,exc) \
	do { \
		try { \
			{ code ; } \
			throw cute::do_not_use_this_namespace::assert_throws_failure_exception((" expecting " #code " to throw " #exc),__FILE__,__LINE__); \
		} catch(exc const &msg){ \
			std::cout << std::endl << "Exception thrown with message: \"" << msg <<"\"" << std::endl; \
		} catch(cute::do_not_use_this_namespace::assert_throws_failure_exception const &atf){throw atf.original;} \
	} while(0)






std::vector<std::string> getDirectories(const std::string& s);
std::vector<std::string> getFiles(const std::string &s);
std::string split(const std::string &s, char delim);
MATFile *readMatfile(std::string file);

template <typename T, int N>
bool getArrayData(MATFile* input, const char* field, coder::array<T, N> &data_out){
	mxArray *arr = matGetVariable(input, field);
	if (arr == NULL ) {
		return false;
	}
	else {
		const mwSize *arr_size = mxGetDimensions(arr);
		if constexpr(N == 1)
			data_out.set_size(*arr_size);
		else if constexpr(N == 2)
			data_out.set_size(*arr_size, *(arr_size + 1));
		else if constexpr(N == 3)
			data_out.set_size(*arr_size, *(arr_size + 1), *(arr_size + 2));
		else if constexpr(N == 4)
			data_out.set_size(*arr_size, *(arr_size + 1), *(arr_size + 2),
					*(arr_size + 3));
		else
			return false;

		// copy data
		T *data;
		if constexpr(std::is_same<T,mxInt8>::value)
			data = mxGetInt8s(arr);
		else if constexpr(std::is_same<T,mxUint8>::value)
			data = mxGetUint8s(arr);
		else if constexpr(std::is_same<T,mxInt16>::value)
			data = mxGetInt16s(arr);
		else if constexpr(std::is_same<T,mxUint16>::value)
			data = mxGetUint16s(arr);
		else if constexpr(std::is_same<T,mxInt32>::value)
			data = mxGetInt32s(arr);
		else if constexpr(std::is_same<T,mxUint32>::value)
			data = mxGetUint32s(arr);
		else if constexpr(std::is_same<T,mxInt64>::value)
			data = mxGetInt64s(arr);
		else if constexpr(std::is_same<T,mxUint64>::value)
			data = mxGetUint64s(arr);
		else if constexpr(std::is_same<T,mxSingle>::value)
			data = mxGetSingles(arr);
		else if constexpr(std::is_same<T,mxDouble>::value)
			data = mxGetDoubles(arr);
		else if constexpr(std::is_same<T,mxLogical>::value)
			data = mxGetLogicals(arr);
		else
			return false;

		mwSize num = mxGetNumberOfElements(arr);
		if (data != NULL) {
			for (mwSize index=0; index<num; index++)  {
				data_out[index] = *(data + index);
			}
		}
	}
	return true;
}

template <typename T>
struct assertion{
	static void assert1D(std::string test_case, std::string array_name,
			coder::array<T, 1U> &actual, coder::array<T, 1U> &ref,
			double delta) {
		int d0 = ref.size(0);
		for (int i0 = 0; i0 < d0; i0++) {
			T refi = static_cast<double>(ref[i0]);
			T actuali = static_cast<double>(actual[i0]);
			if ((!isnan(refi) && !isnan(actuali))
					&& (!isinf(refi) && !isinf(actuali))) {
				ASSERT_EQUAL_DELTA_DDTM("ERROR: Trace back " + test_case + ":",
						refi, actuali, refi*delta,
						DDTM(" Failed at: "+ array_name + "[" + std::to_string(i0) + "]"));
			}
		}

	}

	static void assert2D(std::string test_case, std::string array_name,
			coder::array<T, 2U> &actual, coder::array<T, 2U> &ref,
			double delta) {
		int d1 = ref.size(1);
		int d0 = ref.size(0);
		for (int i1 = 0; i1 < d1; i1++) {
			for (int i0 = 0; i0 < d0; i0++) {
				T refi = static_cast<double>(ref[i0 + (d0 * i1)]);
				T actuali = static_cast<double>(actual[i0 + (d0 * i1)]);
				if ((!isnan(refi) && !isnan(actuali))
						&& (!isinf(refi) && !isinf(actuali))) {
					ASSERT_EQUAL_DELTA_DDTM(
							"ERROR: Trace back " + test_case + ":",
							refi, actuali, refi*delta,
							DDTM(" Failed at: "+ array_name + "[" + std::to_string(i0) + "][" + std::to_string(i1) + "]"));
				}
			}
		}
	}

	static void assert3D(std::string test_case, std::string array_name,
			coder::array<T, 3U> &actual, coder::array<T, 3U> &ref,
			double delta) {
		int d2 = ref.size(2);
		int d1 = ref.size(1);
		int d0 = ref.size(0);
		for (int i2 = 0; i2 < d2; i2++) {
			for (int i1 = 0; i1 < d1; i1++) {
				for (int i0 = 0; i0 < d0; i0++) {
					T refi = static_cast<double>(ref[i0 + (d0 * i1) + (d1 * d0 * i2)]);
					T actuali = static_cast<double>(actual[i0 + (d0 * i1) + (d1 * d0 * i2)]);
					if ((!isnan(refi) && !isnan(actuali))
							&& (!isinf(refi) && !isinf(actuali))) {
						ASSERT_EQUAL_DELTA_DDTM(
								"ERROR: Trace back " + test_case + ":",
								refi, actuali, refi*delta,
								DDTM(" Failed at: "+ array_name + "[" + std::to_string(i0) + "][" + std::to_string(i1) + "][" + std::to_string(i2) + "]"));
					}
				}
			}
		}
	}

	static void assert4D(std::string test_case, std::string array_name,
			coder::array<T, 4U> &actual, coder::array<T, 4U> &ref,
			double delta) {
		int d3 = ref.size(3);
		int d2 = ref.size(2);
		int d1 = ref.size(1);
		int d0 = ref.size(0);
		for (int i3 = 0; i3 < d3; i3++) {
			for (int i2 = 0; i2 < d2; i2++) {
				for (int i1 = 0; i1 < d1; i1++) {
					for (int i0 = 0; i0 < d0; i0++) {
						double refi = static_cast<double>(ref[i0 + (d0 * i1) + (d1 * d0 * i2)
								+ (d2 * d1 * d0 * i3)]);
						double actuali = static_cast<double>(actual[i0 + (d0 * i1) + (d1 * d0 * i2)
								+ (d2 * d1 * d0 * i3)]);
						if ((!isnan(refi) && !isnan(actuali))
								&& (!isinf(refi) && !isinf(actuali))) {
							ASSERT_EQUAL_DELTA_DDTM(
									"ERROR: Trace back " + test_case + ":",
									refi, actuali, delta,
									DDTM(" Failed at: "+ array_name + "[" + std::to_string(i0) + "][" + std::to_string(i1) + "][" + std::to_string(i2) + "][" + std::to_string(i3)+ "]"));
						}
					}
				}
			}
		}
	}

	static void assertStatic2D(std::string test_case, std::string array_name,
			T actual[4][4], T ref[4][4], double delta) {
		for (int i1 = 0; i1 < 4; i1++) {
			for (int i0 = 0; i0 < 4; i0++) {
				T refi = static_cast<double>(ref[i0][i1]);
				T actuali = static_cast<double>(actual[i0][i1]);
				if ((!isnan(refi) && !isnan(actuali))
						&& (!isinf(refi) && !isinf(actuali))) {
					ASSERT_EQUAL_DELTA_DDTM(
							"ERROR: Trace back " + test_case + ":", refi,
							actuali, refi*delta,
							DDTM(" Failed at: "+ array_name + "[" + std::to_string(i0) + "][" + std::to_string(i1) + "]"));
				}
			}
		}
	}

};

#endif
