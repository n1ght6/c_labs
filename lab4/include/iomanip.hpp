/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>

//{ endm manipulator
inline std::ostream& endm(std::ostream& os) {
    return os << "[eol]\n";
}
//}

//{ squares manipulator
class SquaresProxy {
public:
    explicit SquaresProxy(std::ostream& os) : os_(os) {}
    
    template<typename T>
    std::ostream& operator<<(const T& value) {
        return os_ << '[' << value << ']';
    }

private:
    std::ostream& os_;
};

class SquaresManipulator {};

inline SquaresProxy operator<<(std::ostream& os, const SquaresManipulator&) {
    return SquaresProxy(os);
}

inline SquaresManipulator squares;
//}

//{ add manipulator
class AddFirstWrapper {
public:
    explicit AddFirstWrapper(std::ostream& os) : os_(os) {}
    
    template<typename T1>
    class AddSecondWrapper {
    public:
        AddSecondWrapper(std::ostream& os, const T1& value1) : os_(os), value1_(value1) {}
        
        template<typename T2>
        friend std::ostream& operator<<(const AddSecondWrapper<T1>& wrapper, const T2& value2) {
            return wrapper.os_ << (wrapper.value1_ + value2);
        }

    private:
        std::ostream& os_;
        T1 value1_;
    };
    
    template<typename T1>
    AddSecondWrapper<T1> operator<<(const T1& value1) const {
        return AddSecondWrapper<T1>(os_, value1);
    }

private:
    std::ostream& os_;
};

inline AddFirstWrapper operator<<(std::ostream& os, const struct AddManipulator&) {
    return AddFirstWrapper(os);
}

struct AddManipulator {};
inline AddManipulator add;
//}

#endif // __IOMANIP_HPP__
