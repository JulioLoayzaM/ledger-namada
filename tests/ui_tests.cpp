/*******************************************************************************
*   (c) 2018 - 2023 Zondax AG
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include "gmock/gmock.h"
#include "common.h"

using ::testing::TestWithParam;

class JsonTestsA : public JsonTests_Base {};
class JsonTestsB : public JsonTests_Base {};

INSTANTIATE_TEST_SUITE_P
(
    JsonTestCasesCurrentTxVer,
    JsonTestsA,
    ::testing::ValuesIn(GetJsonTestCases("testvectors.json")),
    JsonTestsA::PrintToStringParamName()
);
TEST_P(JsonTestsA, CheckUIOutput_CurrentTX_Normal) { check_testcase(GetParam(), false); }
TEST_P(JsonTestsA, CheckUIOutput_CurrentTX_Expert) { check_testcase(GetParam(), true); }


INSTANTIATE_TEST_SUITE_P
(
    JsonTestCasesCurrentTxVer,
    JsonTestsB,
    ::testing::ValuesIn(GetJsonTestCases("ibc.json")),
    JsonTestsB::PrintToStringParamName()
);
TEST_P(JsonTestsB, CheckUIOutput_CurrentTX_Normal) { check_testcase(GetParam(), false); }
TEST_P(JsonTestsB, CheckUIOutput_CurrentTX_Expert) { check_testcase(GetParam(), true); }
