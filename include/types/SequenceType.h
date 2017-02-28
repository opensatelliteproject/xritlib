#ifndef _SEQUENCETYPE_H_
#define _SEQUENCETYPE_H_

namespace SequenceType {
    enum SequenceType {
        CONTINUED_SEGMENT = 0,
        FIRST_SEGMENT = 1,
        LAST_SEGMENT = 2,
        SINGLE_DATA = 3
    };
}

#endif