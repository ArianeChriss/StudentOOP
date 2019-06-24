CXXFLAGS=-g -std=c++14 -Wall -pedantic
CC=$(CXX)

STUDENT_DIR=my_code
TEST_DIR=tests

test_hello: $(TEST_DIR)/test_hello

$(TEST_DIR)/test_hello: $(STUDENT_DIR)/hello.cpp $(TEST_DIR)/test_hello.cpp

test_basics: $(TEST_DIR)/test_basics

$(TEST_DIR)/test_basics: $(STUDENT_DIR)/basics.cpp $(TEST_DIR)/test_basics.cpp

test_pointers: $(TEST_DIR)/test_pointers

$(TEST_DIR)/test_pointers: $(STUDENT_DIR)/pointers.cpp $(TEST_DIR)/test_pointers.cpp

test_weather: $(TEST_DIR)/test_weather

$(TEST_DIR)/test_weather: $(STUDENT_DIR)/weather.cpp $(TEST_DIR)/test_weather.cpp

test_complex: $(TEST_DIR)/test_complex

$(TEST_DIR)/test_complex: $(STUDENT_DIR)/complex.cpp $(TEST_DIR)/test_complex.cpp

test_vector: $(TEST_DIR)/test_vector

$(TEST_DIR)/test_vector: $(STUDENT_DIR)/vector.cpp $(TEST_DIR)/test_vector.cpp

test_llist: $(TEST_DIR)/test_llist

$(TEST_DIR)/test_llist: $(STUDENT_DIR)/llist.cpp $(TEST_DIR)/test_llist.cpp


tests: test_hello test_basics test_pointers test_complex test_vector test_llist
	tests/test_hello
	tests/test_basics
	tests/test_pointers
	tests/test_complex
	tests/test_vector
	tests/test_llist

prod: tests
	- git commit -a -m "new assignment done"
	git push origin master
