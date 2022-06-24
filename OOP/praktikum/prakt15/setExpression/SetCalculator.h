//
// Created by nikola354 on 08.06.22.
//

#ifndef SETEXPRESSION_SETCALCULATOR_H
#define SETEXPRESSION_SETCALCULATOR_H

#include <vector>

class SetCalculator {
    class Set;

    class SetExpr {
    public:

        virtual Set &eval() const = 0;

        virtual SetExpr *clone() const = 0;

        virtual ~SetExpr() = default;
    };

    class Operation : public SetExpr {
        SetExpr *left;
        char op;
        SetExpr *right;

    public:
        Operation(SetExpr *left, char op, SetExpr *right) : left(left), right(right), op(op) {
        }

        ~Operation() {
            delete left;
            delete right;
        }

        std::vector<int> disjunction(std::vector<int> set1, std::vector<int> set2) const {

        }

        std::vector<int> conjunction(std::vector<int> set1, std::vector<int> set2) const {

        }

        Set &eval() const override {
            switch (op) {
                case 'v' :
                    return *new Set(disjunction(left->eval().getData(), right->eval().getData()));
                case '^': return *new Set(conjunction(left->eval().getData(), right->eval().getData()));
            }
        }

        SetExpr *clone() const override {
            return new Operation(left->clone(), op, right->clone());
        }


    };

    class Set : public SetExpr {
    private:
        std::vector<int> data;

    public:
        Set(const std::vector<int> &data) : data(data) {
        }

        Set &eval() const override {
            return *new Set(*this);
        }

        SetExpr *clone() const override {
            return new Set(data);
        }

        std::vector<int> getData() const {
            return data;
        }
    };

};


#endif //SETEXPRESSION_SETCALCULATOR_H
