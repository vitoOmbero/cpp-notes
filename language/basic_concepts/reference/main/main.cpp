#include <iostream>

using namespace std;

struct Bro
{
    std::string name;
};

Bro default_bro{ "Default bro" };

class Fua
{
public:
    Fua(std::string str)
        : data_{ str }
        , bro_{ default_bro } {};

    Fua(const Fua&) = default;
    Fua(Fua&&)      = default;

    Fua& operator=(const Fua& that)
    {
        data_ = that.data_;
        bro_  = that.bro_;
        cout << "copy assigned\n";
        return *this;
    };

    Fua& operator=(Fua&& that)
    {
        data_ = std::move(that.data_);
        bro_  = std::move(that.bro_);
        cout << "move assigned\n";
        return *this;
    };
    ;
    ~Fua() = default;

    std::string getData() const;

    Bro& getBro() const;

    void setBro(const Bro& bro);

private:
    std::string data_;
    Bro&        bro_;
};

int main()
{
    Bro one{ "one" };
    Bro two{ "two" };

    Fua a("Qwerty");
    a.setBro(one);

    Fua& b = a;
    Fua* c = new Fua("Zxcvbn");
    c->setBro(two);

    b     = *c;
    Fua d = a;

    cout << d.getData() << endl;
    cout << d.getBro().name << endl;

    delete c;
    return 0;
}

std::string Fua::getData() const
{
    return data_;
}

Bro& Fua::getBro() const
{
    return bro_;
}

void Fua::setBro(const Bro& bro)
{
    bro_ = bro;
}
