//
// Created by speen1 on 2020/3/5.
//

#include "IResample.h"
void IResample::Update(XData data) {

    XData d = this->Resample(data);
    //XLOGE("his->Resample(data) %d",d.size);
    if(d.size > 0)
    {
        this->Notify(d);
    }
}