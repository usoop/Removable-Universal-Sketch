#ifndef CUCKOO_FILTER_STATUS_H_
#define CUCKOO_FILTER_STATUS_H_

namespace cuckoofilter {
    enum Status {
        Ok = 0,
        NotFound = 1,
        NotEnoughSpace = 2,
        NotSupported = 3,
        InsertFailed = 4,
    };
}

#endif
