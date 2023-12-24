#ifndef FLOW_DEFINITON_H_
#define FLOW_DEFINITON_H_

#include <sstream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include "xxhash.h"

using std::string;
#define MIN(a, b) a<b?a:b

#define MAX(a, b) a>b?a:b


static inline uint32_t bswap_32(uint32_t x) {
    x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0x00FF00FF);
    return (x >> 16) | (x << 16);
}


static inline uint16_t bswap_16(uint16_t x) {
    return (x >> 8) | (x << 8);
}


#pragma  pack (1)
namespace datasketches {


    typedef struct Net5Tuple {
        u_int32_t SrcIP;
        u_int32_t DstIP;
        u_int16_t SrcPort;
        u_int16_t DstPort;
        u_int8_t Protocol;
    } net_5_tuple;


    typedef struct Net5TupleWithTotalLenth {
        Net5Tuple Net_5_tuple;
        uint16_t TotalLen;
    } Net5TupleWithTotalLenth;


    uint32_t net_ip_address_to_uint32_with_bigendian(const char *net_addr) {
        uint32_t addr_host = inet_addr(net_addr);
        uint32_t addr_host_bigendian = htonl(addr_host);
        return addr_host_bigendian;
    }


    uint16_t net_port_address_to_uint16_t(const char *port_net_addr) {
        uint16_t port_host_addr = atoi(port_net_addr);
        return port_host_addr;
    }

    uint8_t net_protocal_to_uint8_t(const char *protocal_net) {
        uint8_t protocal_host = atoi(protocal_net);
        return protocal_host;
    }


    Net5Tuple smallendian_to_bigendian_of_net5tuple(Net5Tuple &that) {
        that.SrcIP = bswap_32(that.SrcIP);
        that.DstIP = bswap_32(that.DstIP);
        that.SrcPort = bswap_16(that.SrcPort);
        that.DstPort = bswap_16(that.DstPort);
        that.Protocol = that.Protocol;
        return that;
    }


    Net5TupleWithTotalLenth smallendian_to_bigendian_of_Net5TupleWithTotalLenth(Net5TupleWithTotalLenth &that) {
        that.Net_5_tuple = smallendian_to_bigendian_of_net5tuple(that.Net_5_tuple);
        that.TotalLen = bswap_16(that.TotalLen);
        return that;
    }


    template<class K, class V>
    class FlowRecordList;

    template<class K, class V>
    void flowrecordlist_intersection(FlowRecordList<K, V> &list1, FlowRecordList<K, V> &list2,
                                     FlowRecordList<K, V> &list_out);

    template<typename Key, typename Value>
    std::map<Key, Value>
    merge_maps(std::map<Key, Value> const &lhs, std::map<Key, Value> const &rhs) {
        typedef typename std::map<Key, Value>::const_iterator input_iterator;
        std::map<Key, Value> result;
        for (input_iterator it1 = lhs.begin(), it2 = rhs.begin(), end1 = lhs.end(), end2 = rhs.end();
             it1 != end1 && it2 != end2;) {
            if (it1->first == it2->first) {
                result[it1->first] = MIN(it1->second, it2->second);
                ++it1;
                ++it2;
            } else {
                if (it1->first < it2->first)
                    ++it1;
                else
                    ++it2;
            }
        }
        return result;
    }


    template<class K, class V>
    class FlowRecordList {
    private:

        uint32_t num_;

        uint32_t zero_moment_;
        uint32_t one_moment_;
        uint64_t two_moment_;

        double three_moment_;
        double four_moment_;

        double entropy_;


    public:
        std::vector<std::pair<K, V> > sorted_vecotr_;
        std::map<K, V> flow_map_;

        FlowRecordList() {
            num_ = 0;
            zero_moment_ = 0;
            one_moment_ = 0;
            two_moment_ = 0;
            three_moment_ = 0;
            four_moment_ = 0;

            entropy_ = 0;
        }

        ~FlowRecordList() {
            std::vector<std::pair<K, V> > tmp;
            sorted_vecotr_.swap(tmp);

            std::map<K, V> tmp_map;
            flow_map_.swap(tmp_map);

        }


        uint32_t get_num() {
            return num_;
        }


        void insert_in_flowrecordlist(K key, V val) {
            auto iter = flow_map_.find(key);
            if (iter != flow_map_.end()) {
                val = val + iter->second;
                iter->second = val;
                if (val == 0) {
                    flow_map_.erase(iter);
                    num_--;
                } else if (val < 0) {
                    std::cout << "error, negative after deletion" << std::endl;
                    return;
                }
            } else {
                auto pr = std::make_pair(key, val);
                flow_map_.insert(pr);
                num_++;
            }
        }

        static bool cmp_by_value_greater(const std::pair<K, V> &l, const std::pair<K, V> &r) {
            return l.second > r.second;
        }

        static bool cmp_by_value_smaller(const std::pair<K, V> &l, const std::pair<K, V> &r) {
            return l.second < r.second;
        }

        void write_in_sorted_vector() {
            for (auto it = flow_map_.begin(); it != flow_map_.end(); it++) {
                sorted_vecotr_.push_back(*it);
            }
            std::sort(sorted_vecotr_.begin(), sorted_vecotr_.end(), cmp_by_value_greater);
        }


        void print_sorted_vector(int top_k) {
            int i = 0;
            for (auto it = sorted_vecotr_.begin(); it != sorted_vecotr_.end(); it++) {
                if (i == top_k) {
                    break;
                }
                std::cout << it->first << ":" << it->second << std::endl;
                i++;
            }
        }

        void print_top_k_to_other_vector(int top_k, std::vector<std::pair<K, V> > &vec) {
            int i = 0;
            for (auto it = sorted_vecotr_.begin(); it != sorted_vecotr_.end(); it++) {
                if (i == top_k) {
                    break;
                }
                vec.push_back(*it);

                i++;
            }
        }

        void print_epsilon_HH_to_other_vector(double epsilon, std::vector<std::pair<K, V> > &vec) {
            uint32_t one_moment = get_one_moment();
            double threshold = epsilon * one_moment;
            for (auto it = sorted_vecotr_.begin(); it != sorted_vecotr_.end(); it++) {

                if (it->second >= threshold) {
                    vec.push_back(*it);
                } else {
                    break;
                }
            }
        }

        uint32_t get_num_() {
            return num_;
        }

        void print_on_screen() {
            for (auto it = flow_map_.begin(); it != flow_map_.end(); it++) {
                std::cout << it->first << ":" << it->second << std::endl;
            }
        }

        V query_element_with_key(K key) {
            auto iter = flow_map_.find(key);
            if (iter != flow_map_.end()) {
                return iter->second;
            }
            return 0;
        }


        uint32_t get_top_k_one_moment(int top_k) {
            uint32_t top_k_moment = 0;
            int i = 0;
            for (auto it = sorted_vecotr_.begin(); it != sorted_vecotr_.end(); it++) {
                if (i == top_k) {
                    break;
                }
                top_k_moment = top_k_moment + it->second;
                i++;
            }
            return top_k_moment;
        }


        uint32_t get_zero_moment() {
            zero_moment_ = num_;
            return zero_moment_;
        }


        uint32_t get_one_moment() {
            one_moment_ = 0;
            for (auto it = flow_map_.begin(); it != flow_map_.end(); it++) {
                one_moment_ = one_moment_ + it->second;
            }
            return one_moment_;

        }

        uint64_t get_two_moment() {
            two_moment_ = 0;
            for (auto it = flow_map_.begin(); it != flow_map_.end(); it++) {
                two_moment_ = two_moment_ + uint64_t(pow(it->second, 2));
            }
            return two_moment_;

        }

        double get_entropy() {
            uint64_t xlogx_moment_ = 0;
            for (auto it = flow_map_.begin(); it != flow_map_.end(); it++) {
                xlogx_moment_ = xlogx_moment_ + it->second * uint32_t(log(it->second));
            }

            entropy_ = log(one_moment_) - (xlogx_moment_ * 1.0) / one_moment_;

            return entropy_;

        }

        double get_three_moment() {
            three_moment_ = 0;
            for (auto it = flow_map_.begin(); it != flow_map_.end(); it++) {
                three_moment_ = three_moment_ + uint64_t(pow(it->second, 3));
            }
            return three_moment_;

        }

        double get_four_moment() {
            four_moment_ = 0;
            for (auto it = flow_map_.begin(); it != flow_map_.end(); it++) {
                four_moment_ = four_moment_ + uint64_t(pow(it->second, 4));
            }
            return four_moment_;

        }

        friend void flowrecordlist_intersection(FlowRecordList<K, V> &list1, FlowRecordList<K, V> &list2,
                                                FlowRecordList<K, V> &list_out) {
            list_out.flow_map_ = merge_maps(list1.flow_map_, list2.flow_map_);
            list_out.num_ = list_out.flow_map_.size();
        }


    };

    typedef uint32_t FingerPrint32;

    typedef FlowRecordList<FingerPrint32, uint32_t> FlowFingerprintList;


    template<class A>
    class actual_estimate_tuple {
    public:
        A actual_value_;
        A estimate_value_;

        actual_estimate_tuple(A actual_value, A estimate_value) : actual_value_(actual_value),
                                                                  estimate_value_(estimate_value) {

        }
    };

    template<class A>
    class EstimateList {
    public:
        std::vector<actual_estimate_tuple<A>> estimatelist_;

        EstimateList() {}

        ~EstimateList() {}

        void insert(A actual_count, A estimate_count) {
            actual_estimate_tuple<A> tuple(actual_count, estimate_count);
            estimatelist_.push_back(tuple);
        }

        static bool cmp_by_value_greater(const actual_estimate_tuple<A> &l, const actual_estimate_tuple<A> &r) {
            return l.actual_value_ > r.actual_value_;
        }

        static bool cmp_by_value_smaller(const actual_estimate_tuple<A> &l, const actual_estimate_tuple<A> &r) {
            return l.actual_value_ < r.actual_value_;
        }

        void sort_greater() {
            std::sort(estimatelist_.begin(), estimatelist_.end(), cmp_by_value_greater);
        }

        void sort_smaller() {
            std::sort(estimatelist_.begin(), estimatelist_.end(), cmp_by_value_smaller);
        }

        void print_on_screen() const {
            std::cout << "estimatelist" << std::endl;
            for (auto it = estimatelist_.cbegin(); it != estimatelist_.cend(); it++) {
                actual_estimate_tuple<A> t = (*it);
                std::cout << t.actual_value_ << ":" << t.estimate_value_ << std::endl;
            }
        }

        void write_in_dat(string s, int i, string root_directory) const {


            std::string filename = root_directory + s + std::to_string(i);
            std::ofstream destFile(filename, std::ios::out);
            if (!destFile) {
                std::cout << "error opening destination file." << std::endl;
                return;
            }
            for (auto it = estimatelist_.cbegin(); it != estimatelist_.cend(); it++) {
                actual_estimate_tuple<A> t = (*it);
                destFile << t.actual_value_ << " " << t.estimate_value_ << std::endl;
            }
            destFile.close();

        }

    };

    typedef EstimateList<int> EstimateTotalCountList;

}

#endif