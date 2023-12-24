


#ifndef MOMENT_ESTIMATION_LUS_SKETCH_WITH_CUCKOO_PREFILTER_IMLP_HPP
#define MOMENT_ESTIMATION_LUS_SKETCH_WITH_CUCKOO_PREFILTER_IMLP_HPP
#define LUS_MOMENT_EST_RAW_METHOD
namespace datasketches {
    template<class T, class W1, class W2, class F, class S>
    LusCuckooSketch<T, W1, W2, F, S>::LusCuckooSketch(const LusCuckooSketch &that) {
        memory_access = that.memory_access;

        hash_access = that.hash_access;

        cache_miss_one = that.cache_miss_one;

        cache_miss_two = that.cache_miss_two;
        value_sum = that.value_sum;
        level_ = that.level_;

        seed_ = that.seed_;

        filter_size_ = that.filter_size_;

        sketch_depth_ = that.sketch_depth_;

        sketch_width_ = that.sketch_width_;

        mem_size_ = that.mem_size_;

        epsilon_ = that.epsilon_;

        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<T, W1, int32_t> *[level_ + 1];
        ptr_sketch_ = new datasketches::BaseSketch<T, W2, int32_t> *[level_ + 1];

        ptr_sketch_[level_] = new S(sketch_depth_, sketch_width_, seed_);

        ptr_filter_[level_] = new F(filter_size_);

        for (int i = 0; i <= level_; i++) {
            ptr_levelTotalNum_[i] = that.ptr_levelTotalNum_[i];
        }

        for (int j = 0; j != level_; j++) {
            ptr_sketch_[j] = new S(sketch_depth_, sketch_width_, seed_);
            ptr_filter_[j] = new F(filter_size_);
        }

        for (int i = 0; i < level_ + 1; i++) {
            *(ptr_filter_[i]) = *(that.ptr_filter_[i]);
        }

        for (int i = 0; i < level_ + 1; i++) {
            *(ptr_sketch_[i]) = *(that.ptr_sketch_[i]);
        }

        online_zero_moment = that.online_zero_moment;
        online_one_moment = that.online_one_moment;
        online_two_moment = that.online_two_moment;
        online_xlogx_moment = that.online_xlogx_moment;
        online_three_moment = that.online_three_moment;
        online_four_moment = that.online_four_moment;


    }


    template<class T, class W1, class W2, class F, class S>
    LusCuckooSketch<T, W1, W2, F, S>::LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_width,
                                                      int sketch_seed) {
        level_ = level;
        srand(0);

        seed_ = rand();

        filter_size_ = filter_size;
        sketch_depth_ = sketch_depth;
        sketch_width_ = sketch_width;

        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<T, W1, int32_t> *[level_ + 1];
        ptr_sketch_ = new datasketches::BaseSketch<T, W2, int32_t> *[level_ + 1];

        mem_size_ = 0;
        value_sum = 0;
        memory_access = 0;

        hash_access = 0;

        cache_miss_one = 0;
        cache_miss_two = 0;
        ptr_levelTotalNum_ = new int[level + 1]();


        ptr_sketch_[level] = new S(sketch_depth, sketch_width, sketch_seed);

        ptr_filter_[level] = new F(filter_size);

        for (uint32_t j = 0; j != level; j++) {
            ptr_sketch_[j] = new S(sketch_depth, sketch_width, sketch_seed);
            ptr_filter_[j] = new F(filter_size);
            mem_size_ = mem_size_ + sketch_depth_ * sketch_width;
        }


        online_zero_moment = 0;
        online_one_moment = 0;
        online_two_moment = 0;
        online_xlogx_moment = 0;
        online_three_moment = 0;
        online_four_moment = 0;
    }

    template<class T, class W1, class W2, class F, class S>
    LusCuckooSketch<T, W1, W2, F, S>::LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_seed,
                                                      vector <int32_t> init_sketch_widths) {
        level_ = level;
        srand(0);

        seed_ = rand();

        filter_size_ = filter_size;
        sketch_depth_ = sketch_depth;


        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<T, W1, int32_t> *[level_ + 1];
        ptr_sketch_ = new datasketches::BaseSketch<T, W2, int32_t> *[level_ + 1];

        mem_size_ = 0;
        value_sum = 0;
        memory_access = 0;

        hash_access = 0;

        cache_miss_one = 0;
        cache_miss_two = 0;
        ptr_levelTotalNum_ = new int[level + 1]();


        ptr_sketch_[level] = new S(sketch_depth, init_sketch_widths[0], sketch_seed);

        ptr_filter_[level] = new F(filter_size);

        for (uint32_t j = 0; j != level; j++) {
            ptr_sketch_[j] = new S(sketch_depth, init_sketch_widths[j + 1], sketch_seed);
            ptr_filter_[j] = new F(filter_size);

        }


        online_zero_moment = 0;
        online_one_moment = 0;
        online_two_moment = 0;
        online_xlogx_moment = 0;
        online_three_moment = 0;
        online_four_moment = 0;
    }


    template<class T, class W1, class W2, class F, class S>
    LusCuckooSketch<T, W1, W2, F, S>::LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_seed,
                                                      vector <int32_t> init_sketch_widths,
                                                      vector <int32_t> init_filter_widths) {
        level_ = level;
        srand(0);

        seed_ = rand();


        filter_size_ = filter_size;
        sketch_depth_ = sketch_depth;


        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<T, W1, int32_t> *[level_ + 1];
        ptr_sketch_ = new datasketches::BaseSketch<T, W2, int32_t> *[level_ + 1];

        mem_size_ = 0;
        value_sum = 0;
        memory_access = 0;

        hash_access = 0;

        cache_miss_one = 0;
        cache_miss_two = 0;
        ptr_levelTotalNum_ = new int[level + 1]();


        ptr_sketch_[level] = new S(sketch_depth, init_sketch_widths[0], sketch_seed);

        ptr_filter_[level] = new F(init_filter_widths[0]);

        for (uint32_t j = 0; j != level; j++) {
            ptr_sketch_[j] = new S(sketch_depth, init_sketch_widths[j + 1], sketch_seed);
            ptr_filter_[j] = new F(init_filter_widths[j + 1]);

        }


        online_zero_moment = 0;
        online_one_moment = 0;
        online_two_moment = 0;
        online_xlogx_moment = 0;
        online_three_moment = 0;
        online_four_moment = 0;
    }

    template<class T, class W1, class W2, class F, class S>
    LusCuckooSketch<T, W1, W2, F, S>::LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_width,
                                                      int sketch_seed,
                                                      double epsilon) {
        level_ = level;

        srand(0);
        seed_ = rand();

        epsilon_ = epsilon;

        filter_size_ = filter_size;
        sketch_depth_ = sketch_depth;
        sketch_width_ = sketch_width;

        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<T, W1, int32_t> *[level_ + 1];
        ptr_sketch_ = new datasketches::BaseSketch<T, W2, int32_t> *[level_ + 1];
        value_sum = 0;
        mem_size_ = 0;

        memory_access = 0;

        hash_access = 0;

        cache_miss_one = 0;
        cache_miss_two = 0;
        ptr_levelTotalNum_ = new int[level + 1]();

        ptr_sketch_[level] = new S(sketch_depth, sketch_width, sketch_seed);

        ptr_filter_[level] = new F(filter_size);

        for (int j = 0; j != level; j++) {
            ptr_sketch_[j] = new S(sketch_depth, sketch_width, sketch_seed);
            ptr_filter_[j] = new F(filter_size);
            mem_size_ = mem_size_ + sketch_depth_ * sketch_width;

        }

        online_zero_moment = 0;
        online_one_moment = 0;
        online_two_moment = 0;
        online_xlogx_moment = 0;
        online_three_moment = 0;
        online_four_moment = 0;
    }


    template<class T, class W1, class W2, class F, class S>
    int LusCuckooSketch<T, W1, W2, F, S>::get_mem_size() {
        return mem_size_;
    }

    template<class T, class W1, class W2, class F, class S>
    LusCuckooSketch<T, W1, W2, F, S>::~LusCuckooSketch() {


        delete ptr_filter_;
        delete ptr_sketch_;
        delete ptr_levelTotalNum_;
    }


    template<class T, class W1, class W2, class F, class S>
    int LusCuckooSketch<T, W1, W2, F, S>::sample_to_level(T new_id) {
        uint32_t rnd = datasketches::XXH_H32(&new_id, sizeof(new_id), seed_);
        return get_longest_len_of_series_one(rnd, level_);
    }

    template<class T, class W1, class W2, class F, class S>
    std::string LusCuckooSketch<T, W1, W2, F, S>::get_class_name() {
        return "LusCuckooSketch";
    }

    template<class T, class W1, class W2, class F, class S>
    void LusCuckooSketch<T, W1, W2, F, S>::print_filter() {
        for (int i = level_ + 1; i != 0; i--) {
            std::cout << "level:" << i - 1 << "        totalcount:" << ptr_sketch_[i - 1]->totalcount() << std::endl;
            ptr_filter_[i - 1]->print_filter();

        }
    }

    template<class T, class W1, class W2, class F, class S>
    bool LusCuckooSketch<T, W1, W2, F, S>::checkmembership_in_filter_at_level_k(const T &new_id, int k) {
        if (ptr_filter_[k]->check_membership(new_id) == -1)
            return 0;

        return 1;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_one_moment() {
        long double one_moment = 0;
        one_moment = compute_moment(datasketches::x_one_moment);
        return one_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_one_moment_by_eps() {
        long double one_moment = 0;
        one_moment = compute_moment_by_eps(datasketches::x_one_moment);
        return one_moment;
    }


    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_one_moment2() {
        long double one_moment = 0;
        one_moment = compute_moment2(datasketches::x_one_moment);
        return one_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_zero_moment() {
        long double zero_moment = 0;
        zero_moment = compute_moment(datasketches::x_zero_moment);
        return zero_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_zero_moment_by_eps() {
        long double zero_moment = 0;
        zero_moment = compute_moment_by_eps(datasketches::x_zero_moment);
        return zero_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_two_moment() {
        long double two_moment = 0;
        two_moment = compute_moment(datasketches::x_two_moment);
        return two_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_two_moment_by_eps() {
        long double two_moment = 0;
        two_moment = compute_moment_by_eps(datasketches::x_two_moment);
        return two_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_xlogx_moment() {
        long double xlogx_moment = 0;
        xlogx_moment = compute_moment(datasketches::x_xlogx_moment);
        return xlogx_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_xlogx_moment_by_eps() {
        long double xlogx_moment = 0;
        xlogx_moment = compute_moment_by_eps(datasketches::x_xlogx_moment);
        if (xlogx_moment > 500000) {


        }
        return xlogx_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_three_moment() {
        long double three_moment = 0;
        three_moment = compute_moment(datasketches::x_three_moment);
        return three_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_three_moment_by_eps() {
        long double three_moment = 0;
        three_moment = compute_moment_by_eps(datasketches::x_three_moment);
        return three_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_four_moment() {
        long double four_moment = 0;
        four_moment = compute_moment(datasketches::x_four_moment);
        return four_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_four_moment_by_eps() {
        long double four_moment = 0;
        four_moment = compute_moment_by_eps(datasketches::x_four_moment);
        return four_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::get_totalcount() {
        return value_sum;
    }

    template<class T, class W1, class W2, class F, class S>
    void LusCuckooSketch<T, W1, W2, F, S>::reset() {

        memory_access = 0;
        hash_access = 0;
        cache_miss_one = 0;
        cache_miss_two = 0;

        online_zero_moment = 0;
        online_one_moment = 0;
        online_two_moment = 0;
        online_xlogx_moment = 0;
        online_three_moment = 0;
        online_four_moment = 0;

        value_sum = 0;

        seed_ = rand();
        for (uint32_t j = 0; j != level_ + 1; j++) {
            ptr_sketch_[j]->reset();
            ptr_filter_[j]->reset();
            ptr_levelTotalNum_[j] = 0;


        }
    }

    template<class T, class W1, class W2, class F, class S>
    void LusCuckooSketch<T, W1, W2, F, S>::get_hhs(vector <std::pair<T, W1>> &vec) {

        W1 value;

        T id;
        for (int j = 0; j != filter_size_; j++) {
            ptr_filter_[0]->get_element_with_index(j, id, value);
            auto pr = make_pair(id, value);
            vec.push_back(pr);
        }
    }

    template<class T, class W1, class W2, class F, class S>
    void LusCuckooSketch<T, W1, W2, F, S>::get_hhs(vector <std::pair<T, uint32_t>> &vec) {


        W1 value;

        T id;
        for (int j = 0; j != filter_size_; j++) {
            ptr_filter_[0]->get_element_with_index(j, id, value);
            auto pr = make_pair(id, get_value_to_int32t(value));
            vec.push_back(pr);
        }


    }

    template<class T, class W1, class W2, class F, class S>
    W2 LusCuckooSketch<T, W1, W2, F, S>::estimate_flow_size_by_sketch_at_level_k(T new_id, uint32_t new_count, int k) {
        return ptr_sketch_[k]->update(new_id, new_count);
    }

    template<class T, class W1, class W2, class F, class S>
    uint32_t LusCuckooSketch<T, W1, W2, F, S>::estimate_flow_size_at_level_k(T new_id, uint32_t new_count, int k) {
        int index = ptr_filter_[k]->check_membership(new_id);
        if (index != -1) {

            return get_value_to_int32t(ptr_filter_[k]->get_value_with_index(index)) + new_count;
        } else if (ptr_filter_[k]->isFull() != true) {

            return get_value_to_int32t(new_count);

        } else {
            memory_access += 5;
            hash_access += 4;
            cache_miss_one++;

            return get_value_to_int32t(estimate_flow_size_by_sketch_at_level_k(new_id, new_count, k));
        }
    }


    template<class T, class W1, class W2, class F, class S>
    uint32_t
    LusCuckooSketch<T, W1, W2, F, S>::estimate_flow_size_at_level_k_by_cuckoo(T new_id, uint32_t new_count, int k) {
        size_t index;
        uint16_t heap_index;
        int isfound = ptr_filter_[k]->check_membership_and_get_index_heapindex(new_id, index, heap_index);
        if (isfound == 1) {
            return ptr_filter_[k]->get_value_by_index_heapindex(index, heap_index) + new_count;
        } else if (ptr_filter_[k]->bucket_has_empty(index, new_id) == 1) {
            return get_value_to_int32t(new_count);
        } else {
            memory_access += 5;
            hash_access += 4;
            cache_miss_one++;

            return get_value_to_int32t(estimate_flow_size_by_sketch_at_level_k(new_id, new_count, k));
        }
    }


    template<class T, class W1, class W2, class F, class S>
    void LusCuckooSketch<T, W1, W2, F, S>::update_lus_with_online_query(T f_id, int32_t new_count) {


        value_sum = value_sum + new_count;
        int32_t f_size_int = 0;
        int jstar = sample_to_level(f_id);
        ptr_levelTotalNum_[jstar] += new_count;

        f_size_int = estimate_flow_size_at_level_k_by_cuckoo(f_id, new_count, jstar);

        T f_pre_id = 0;
        int32_t f_pre_size_int = 0;

        int j_old = jstar + 1;
        int j_new = jstar + 1;
        size_t index;
        uint16_t heap_index;
        for (int j = jstar; j >= 0; j--) {

            int isfound = ptr_filter_[jstar]->check_membership_and_get_index_heapindex(f_id, index, heap_index);

            if (isfound == 1) {
                ptr_filter_[j]->set_value_with_index_heapindex(index, heap_index, f_size_int);

                j_old = j;
            } else {
                uint32_t tag = f_id;
                int isInserted = ptr_filter_[jstar]->try_insert_to_empty(index, tag, f_size_int);
                if (isInserted != 1) {
                    T out_id;
                    W1 out_size_w1;
                    W1 out_size_int;
                    W1 old_size_int;

                    ptr_filter_[j]->get_min_from_histogram();

                    out_size_int = out_size_w1;
                    if (f_size_int <= out_size_int)
                        break;
                    if (f_pre_id != out_id) {
                        if (f_pre_id != 0) {


                            online_zero_moment = online_zero_moment - pow(2, j + 1) * x_zero_moment(f_pre_size_int);
                            online_one_moment = online_one_moment - pow(2, j + 1) * x_one_moment(f_pre_size_int);
                            online_two_moment = online_two_moment - pow(2, j + 1) * x_two_moment(f_pre_size_int);
                            online_xlogx_moment = online_xlogx_moment - pow(2, j + 1) * x_xlogx_moment(f_pre_size_int);

                        }
                        f_pre_id = out_id;
                        f_pre_size_int = out_size_int;
                        int j_out_star = sample_to_level(out_id);
                        if (j == j_out_star) {

                            T kicked_item;
                            uint32_t kicked_new_freq;
                            uint32_t kicked_old_freq;
                            int InsertSucceed = ptr_filter_[j]->try_kick(index, tag, f_size_int, kicked_item,
                                                                         kicked_new_freq, kicked_old_freq);
                            if (InsertSucceed == 1 & kicked_new_freq != 0) {
                                ptr_sketch_[j]->update(out_id, get_value_to_int32t(out_size_int - old_size_int));


                            }


                        }
                        if (j + 1 <= j_out_star) {


                            online_zero_moment = online_zero_moment + (1 << (j + 1)) * x_zero_moment(out_size_int);
                            online_one_moment = online_one_moment + (1 << (j + 1)) * x_one_moment(out_size_int);
                            online_two_moment = online_two_moment + (1 << (j + 1)) * x_two_moment(out_size_int);
                            online_xlogx_moment = online_xlogx_moment + (1 << (j + 1)) * x_xlogx_moment(out_size_int);

                        }
                    }

                }
                j_new = j;
            }
            if (j_old <= jstar) {


                online_zero_moment = online_zero_moment - (1 << j_old) * x_zero_moment(f_size_int - new_count);
                online_one_moment = online_one_moment - (1 << j_old) * x_one_moment(f_size_int - new_count);
                online_two_moment = online_two_moment - (1 << j_old) * x_two_moment(f_size_int - new_count);
                online_xlogx_moment = online_xlogx_moment - (1 << j_old) * x_xlogx_moment(f_size_int - new_count);

            }
            if (j_new <= jstar) {


                online_zero_moment = online_zero_moment + (1 << j_new) * x_zero_moment(f_size_int);
                online_one_moment = online_one_moment + (1 << j_new) * x_one_moment(f_size_int);
                online_two_moment = online_two_moment + (1 << j_new) * x_two_moment(f_size_int);
                online_xlogx_moment = online_xlogx_moment + (1 << j_new) * x_xlogx_moment(f_size_int);

            }
            if (j_new < j_old) {


                online_zero_moment = online_zero_moment - (1 << j_new) * x_zero_moment(f_pre_size_int);
                online_one_moment = online_one_moment - (1 << j_new) * x_one_moment(f_pre_size_int);
                online_two_moment = online_two_moment - (1 << j_new) * x_two_moment(f_pre_size_int);
                online_xlogx_moment = online_xlogx_moment - (1 << j_new) * x_xlogx_moment(f_pre_size_int);

            }
        }
    }


    template<class T, class W1, class W2, class F, class S>
    void LusCuckooSketch<T, W1, W2, F, S>::update_lus(T f_id, int32_t new_count) {

        value_sum = value_sum + new_count;
        int32_t f_size_int = 0;
        int jstar = sample_to_level(f_id);
        ptr_levelTotalNum_[jstar] += new_count;
        hash_access += 1;
        size_t index;
        uint16_t heap_index;

        int isfound = ptr_filter_[jstar]->check_membership_and_get_index_heapindex(f_id, index, heap_index);

        if (isfound == 1) {

            W1 tmp = ptr_filter_[jstar]->get_value_by_index_heapindex(index, heap_index);
            f_size_int = tmp + new_count;
            ptr_filter_[jstar]->set_value_with_index_heapindex(index, heap_index, f_size_int);


        } else {
            f_size_int = new_count;
            uint32_t tag = f_id;
            int isInserted = ptr_filter_[jstar]->try_insert_to_empty(index, tag, f_size_int);
            if (isInserted != 1) {

                memory_access += 5;
                hash_access += 4;
                cache_miss_one++;
                W2 est_;
                est_ = 0;
                W2 est_value;
                est_value = 0;
                est_value = estimate_flow_size_by_sketch_at_level_k(f_id, new_count, jstar);
                f_size_int = get_value_to_int32t(est_value);
                T out_id;
                W1 out_size_w1;

                W1 out_size_int;
                W1 old_size_int;

                out_size_int = ptr_filter_[jstar]->get_min_from_histogram();
                if (f_size_int <= out_size_int)
                    return;

                int j_out_star = sample_to_level(out_id);
                hash_access += 1;
                if (jstar == j_out_star) {
                    T kicked_item;
                    uint32_t kicked_new_freq;
                    uint32_t kicked_old_freq;
                    int InsertSucceed = ptr_filter_[jstar]->try_kick(index, tag, f_size_int, kicked_item,
                                                                     kicked_new_freq, kicked_old_freq);


                    if (InsertSucceed == 1 & kicked_new_freq != 0) {
                        ptr_sketch_[jstar]->update(out_id, get_value_to_int32t(out_size_int - old_size_int));


                        cache_miss_two++;
                        memory_access += 5;
                        hash_access += 4;
                    }
                }


            }


        }
        for (int j = jstar - 1; j >= 0; j--) {

            isfound = ptr_filter_[jstar]->check_membership_and_get_index_heapindex(f_id, index, heap_index);

            if (isfound == 1) {
                ptr_filter_[jstar]->set_value_with_index_heapindex(index, heap_index, f_size_int);
            } else {
                uint32_t tag = f_id;
                int isInserted = ptr_filter_[jstar]->try_insert_to_empty(index, tag, f_size_int);
                if (isInserted != 1) {
                    T out_id;
                    W1 out_size_w1;
                    W1 out_size_int;
                    W1 old_size_int;
                    out_size_int = ptr_filter_[j]->get_min_from_histogram();
                    out_size_int = out_size_w1;
                    if (f_size_int <= out_size_int)
                        break;

                    int j_out_star = sample_to_level(out_id);
                    hash_access += 1;
                    if (j == j_out_star) {

                        T kicked_item;
                        uint32_t kicked_new_freq;
                        uint32_t kicked_old_freq;
                        int InsertSucceed = ptr_filter_[j]->try_kick(index, tag, f_size_int, kicked_item,
                                                                     kicked_new_freq, kicked_old_freq);
                        if (InsertSucceed == 1 & kicked_new_freq != 0) {
                            ptr_sketch_[j]->update(out_id, get_value_to_int32t(out_size_int - old_size_int));
                            cache_miss_two++;
                            memory_access += 5;
                            hash_access += 4;
                        }
                    }
                }
            }
        }
    }


    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_moment(long double (*f)(int32_t x)) {
        long double x_moment = 0;
        W1 value;
        uint32_t uint_value = 0;
        long double uint64_value = 0;
        T id;
        bool is_in_lower_level;


        for (int i = level_; i != 0; i--) {


            int t_level = i;

            int filter_size = ptr_filter_[t_level]->get_filter_size();
            for (int j = 0; j != filter_size; j++) {
                ptr_filter_[t_level]->get_element_with_index(j, id, value);
                is_in_lower_level = checkmembership_in_filter_at_level_k(id, t_level - 1);


                if (is_in_lower_level == 0) {


                    uint_value = get_value_to_int32t(value);


                    if (uint_value != uint32_t(0)) {
                        uint64_value = f(uint_value);
                        x_moment = x_moment + uint64_value * std::pow(2, t_level);
                    }
                }
            }
        }


        int filter_size = ptr_filter_[0]->get_filter_size();
        for (int j = 0; j != filter_size; j++) {
            ptr_filter_[0]->get_element_with_index(j, id, value);
            uint_value = get_value_to_int32t(value);
            if (uint_value != uint32_t(0)) {
                uint64_value = f(uint_value);
                x_moment = x_moment + uint64_value;
            }

        }
        return x_moment;
    }

    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_moment_by_eps(long double(*f)(uint32_t x)) {
        long double x_moment = 0;
        W1 value;
        uint32_t uint_value = 0;
        long double uint64_value = 0;
        T id;
        bool is_in_lower_level;


        for (int i = level_; i != 0; i--) {

            int t_level = i;


            int filter_size = ptr_filter_[t_level]->get_filter_size();


            for (int j = 0; j != filter_size; j++) {
                ptr_filter_[t_level]->get_element_with_index(j, id, value);
                is_in_lower_level = checkmembership_in_filter_at_level_k(id, t_level - 1);
                if (is_in_lower_level == 0) {
                    uint_value = get_value_to_uint32t(value);

                    if (uint_value != uint32_t(0)) {


                        uint64_value = f(uint_value);
                        x_moment = x_moment + uint64_value * std::pow(2, t_level);
                    }
                }
            }
        }


        int filter_size = ptr_filter_[0]->get_filter_size();


        for (int j = 0; j != filter_size; j++) {
            ptr_filter_[0]->get_element_with_index(j, id, value);
            uint_value = get_value_to_uint32t(value);


            uint64_value = f(uint_value);

            x_moment = x_moment + uint64_value;
        }
        return x_moment;
    }


    template<class T, class W1, class W2, class F, class S>
    long double LusCuckooSketch<T, W1, W2, F, S>::compute_moment2(long double(*f)(uint32_t x)) {

#ifdef LUS_MOMENT_EST_RAW_METHOD

        long double x_moment = 0;
        W1 value;
        T id;

        int highest_level = level_;
        int existsInUpperLevelFlag = 0;
        for (int t_level = level_; t_level >= 0; t_level--) {
            int filter_size = ptr_filter_[t_level]->get_filter_size();
            x_moment *= 2;

            for (int j = 0; j != filter_size; j++) {
                ptr_filter_[t_level]->get_element_with_index(j, id, value);
                highest_level = sample_to_level(id);
                existsInUpperLevelFlag = highest_level > t_level ? 1 : 0;
                x_moment += (1 - 2 * existsInUpperLevelFlag) * f(get_value_to_uint32t(value));
            }
        }
        return x_moment;

#elif

        uint64_t x_moment = 0;
        uint64_t x_moment_upper = 0;
        W1 value;
        uint32_t uint_value = 0;
        uint64_t uint64_value = 0;
        T id;
        bool is_in_lower_level;

        for (int i = level_; i != -1; i--) {
            x_moment = 2 * x_moment;
            int t_level = i;
            int filter_size = ptr_filter_[t_level]->get_filter_size();
            for (int j = 0; j != filter_size; j++) {
                ptr_filter_[t_level]->get_element_with_index(j, id, value);
                int t_sample_level = sample_to_level(id);
                int hf = 0;
                if (t_level < t_sample_level)
                    hf = 1;
                uint_value = get_value_to_uint32t(value);
                if (uint_value != uint32_t(0)) {
                    uint64_value = f(uint_value);
                    x_moment = x_moment + uint64_value * (1 - 2 * hf);
                }

            }
        }

        return x_moment;
#endif
    }


    template<class T, class W1, class W2, class F, class S>
    LusCuckooSketch <T, W1, W2, F, S> &LusCuckooSketch<T, W1, W2, F, S>::operator=(const LusCuckooSketch &that) {
        if (this == &that)
            return *this;
        memory_access = that.memory_access;

        hash_access = that.hash_access;

        cache_miss_one = that.cache_miss_one;

        cache_miss_two = that.cache_miss_two;

        level_ = that.level_;

        seed_ = that.seed_;

        filter_size_ = that.filter_size_;

        sketch_depth_ = that.sketch_depth_;

        sketch_width_ = that.sketch_width_;

        mem_size_ = that.mem_size_;

        epsilon_ = that.epsilon_;

        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<T, W1, int32_t> *[level_ + 1];
        ptr_sketch_ = new datasketches::BaseSketch<T, W2, int32_t> *[level_ + 1];

        ptr_sketch_[level_] = new S(sketch_depth_, sketch_width_, seed_);

        ptr_filter_[level_] = new F(filter_size_);

        for (int j = 0; j != level_; j++) {
            ptr_sketch_[j] = new S(sketch_depth_, sketch_width_, seed_);
            ptr_filter_[j] = new F(filter_size_);
        }

        for (int i = 0; i < level_ + 1; i++) {
            *(ptr_filter_[i]) = *(that.ptr_filter_[i]);
        }
        for (int i = 0; i < level_ + 1; i++) {
            *(ptr_sketch_[i]) = *(that.ptr_sketch_[i]);
        }
        return *this;
    }
}

#endif
