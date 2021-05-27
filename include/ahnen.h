#ifndef AHNEN_H
#define AHNEN_H

#include <string>
#include <string_view>
#include <vector>

class Ahnen {
    std::string num_;
    std::string name_;
    
public:
    
    Ahnen(const std::string_view& num, const std::string_view& name) : num_{num}, name_{name} {}
    Ahnen(Ahnen&& lhs) = default;
    Ahnen(const Ahnen&) = default;
    
    const std::string& number() const
    {
        return num_;
    }
    
    const std::string& name() const
    {
        return name_;
    }
    
};

std::vector<Ahnen> build_ahnen(const std::string& fname);

#endif /* AHNEN_H */

