#include <string>

class  department_budget{
private:
    std::string name_;
    double budget_;
    double current_balance_;
public:

    std::string fileName_;

    const std::string &getFileName_() const;

    void setFileName_(const std::string &fileName_);

    department_budget();

    department_budget(const std::string &fileName);

    const std::string &getName_() const;

    void setName_(const std::string &name_);

    double getBudget_() const;

    void setBudget_(double budget_);

    double getCurrent_balance_() const;

    void setCurrent_balance_(double current_balance_);


};
