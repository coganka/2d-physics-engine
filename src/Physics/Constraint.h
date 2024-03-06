#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "Body.h"
#include "MatMN.h"


class Constraint {
    public:
        Body* a;
        Body* b;

        Vec2 aPoint;
        Vec2 bPoint;

        virtual ~Constraint() = default;

        MatMN GetInvM() const;
        VecN GetVelocities() const;

        virtual void PreSolve(const float dt) {}
        virtual void Solve() {}
};


class JointConstraint: public Constraint {
    private:
        MatMN jacobian;
        VecN cachedLambda;
        float bias;
    
    public:
        JointConstraint();
        JointConstraint(Body* a, Body* b, const Vec2& anchorPoint);
        void PreSolve(const float dt) override;
        void Solve() override;
};

class PenetrationConstraint: public Constraint {
    private:
        MatMN jacobian;
        VecN cachedLambda;
        float bias;
        Vec2 normal;    //normal direction of the penetration in a's local space
        float friction; //friction coefficient between the two penetrating bodies
    
    public:
        PenetrationConstraint();
        PenetrationConstraint(Body* a, Body* b, const Vec2& aCollisionPoint, const Vec2& bCollisionPoint, const Vec2& normal);
        void PreSolve(const float dt) override;
        void Solve() override;
};


#endif