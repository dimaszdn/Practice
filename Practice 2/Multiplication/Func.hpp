#pragma once
#include<vector>
#include<iostream>

std::vector<int> transformation(std::string str);

int maxSize(int len1, int len2);

void equal_length(std::vector<int>& v, int len);

std::vector<int> usualMul(std::vector<int>v1, std::vector<int>v2);

std::vector<int> karatsubaMul(std::vector<int>v1, std::vector<int>v2);

void remains(std::vector<int>& v);

void reSize(std::vector<int>& v, int len);

void print(std::vector<int> v);
