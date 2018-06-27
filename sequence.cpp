#include <iostream>
#include <cassert>
#include "sequence1.h"

using namespace std;

using namespace main_savitch_3;

    sequence::sequence() {
        data[CAPACITY];
        used = 0;
        current_index = 0;
    }

    void sequence::start() {
        if (used > 0) {
            current_index = 0;
        }
    }

    void sequence::advance() {
        if (is_item() == true) {
            current_index += 1;
        }
    }

    void sequence::insert(const value_type& entry) {
        size_type i;
        assert(size() < CAPACITY);

        if (is_item() == false) {
            current_index = 0;
        }
        for (i = used; i > current_index; i--) {
            data[i] = data[i-1];
        }
        data[current_index] = entry;
        used += 1;
    }

    void sequence::attach(const value_type& entry) {
        size_type i;
        assert(size() < CAPACITY);
        if (is_item() == false) {
            current_index = size();
            data[current_index] = entry;
            used += 1;
        } else {
            for (i = size(); i > current_index + 1; i--) {
                data[i] = data[i-1];
            }
            current_index += 1;
            data[current_index] = entry;
            used += 1;
        }
    }

    void sequence::remove_current() {
        size_type i;
        assert(is_item());
        for (i = current_index; i < size() - 1; i++) {
            data[i] = data[i+1];
        }
        used -= 1;
    }

    sequence::size_type sequence::size() const {
        return used;
    }

    bool sequence::is_item() const {
        if (current_index >=0 && current_index < used) {
            return true;
        } else {
            return false;
        }
    }

    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }







