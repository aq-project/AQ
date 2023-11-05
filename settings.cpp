/*#include <iostream>
#include "aq_main.h"
#include <curl/curl.h> 

std::string bns_querier(std::string query_address){
	CURL *bns_querier = curl_easy_init();
	if (bns_querier) {
		curl_easy_setopt(bns_querier,CURLOPT_URL,query_address.c_str());
		std::string result_address;
		curl_easy_setopt(bns_querier,CURLOPT_WRITEFUNCTION,write_callback);
		curl_easy_setopt(bns_querier,CURLOPT_WRITEDATA,&result_address);
		CURLcode result = curl_easy_perform(bns_querier);
		if (result != CURLE_OK) {
			std::cout << "test result:" << curl_easy_strerror(result) << std::endl;
		}
		else {
			std::cout << result << std::endl;

		}
		curl_easy_cleanup(bns_querier);
	}
	else {
		return "not run";
	}
	
}
size_t write_callback(void* buffer, size_t size, size_t nmemb, std::string* s) {
	size_t total_size = size * nmemb;
	s->append((char*)buffer, total_size);
	return total_size;
}*/