/*
 * netchecker_profile.h
 *
 *  Created on: 2016年4月11日
 *      Author: caoshaokun
 */

#ifndef SDT_SRC_NETCHECKER_PROFILE_H_
#define SDT_SRC_NETCHECKER_PROFILE_H_

#include <string>
#include <vector>
#include <map>
#include <stdint.h>

#include "mars/sdt/sdt.h"
#include "mars/sdt/constants.h"

namespace mars {
namespace sdt  {

struct CheckResultProfile {

	CheckResultProfile() {
		Reset();
	}

	void Reset() {
		netcheck_type = -1;

		error_code = 0;
		network_type = 0;

		ip.clear();
		port = 0;
		conntime = 0;
		rtt = 0;

		url.clear();
		status_code = 0;

		checkcount = 0;
		loss_rate.clear();

		domain_name.clear();
		local_dns.clear();
		ip1.clear();
		ip2.clear();
	}

	int netcheck_type;	//ping dns tcp http

    int error_code;
    int network_type;

    std::string ip;		//ping tcp http
	unsigned int port;	//tcp http
    uint64_t conntime;
    uint64_t rtt;		//tcp http rtt, dns resolve time
    std::string rtt_str;	//ping

    std::string url;
    int status_code;	//http

    unsigned int checkcount;	//ping
    std::string loss_rate;		//ping

    std::string domain_name;	//dns host
    std::string local_dns;		//dns
    std::string ip1;			//dns
    std::string ip2;			//dns

};

struct CheckRequestProfile {

	CheckRequestProfile() {
		Reset();
	}

	void Reset() {
		longlink_items.clear();
		shortlink_items.clear();

		checkresult_profiles.clear();
		mode = NET_CHECK_BASIC;
		check_status = kCheckContinue;

		total_timeout = 0;
	}

	CheckIPPorts longlink_items;
	CheckIPPorts shortlink_items;

	int	mode;
	CheckStatus check_status;

	uint32_t total_timeout;

	std::vector<CheckResultProfile> checkresult_profiles;

};

}}

#endif /* SDT_SRC_NETCHECKER_PROFILE_H_ */