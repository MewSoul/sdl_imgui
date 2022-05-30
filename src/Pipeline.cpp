
#include "Pipeline.h"

Pipeline::Pipeline(ecs_world_t *pWorld) {
    mOnInput = ecs_new_id(pWorld);
    mOnUpdate = ecs_new_id(pWorld);
    mOnDraw = ecs_new_id(pWorld);

    ecs_type_desc_t pipelineDesc {
            .entity = {
                    .name = "CustomPipeline",
                    .add = {EcsPipeline}
            },
            .ids = {EcsPreFrame,mOnInput,mOnUpdate,mOnDraw,EcsPostFrame}
    };

    mPipeline = ecs_type_init(pWorld, &pipelineDesc);
    ecs_add_id(pWorld, mPipeline, EcsPipeline);
}

ecs_entity_t Pipeline::GetPipeline() const {
    return mPipeline;
}

ecs_entity_t Pipeline::GetInputPhase() const {
    return mOnInput;
}

ecs_entity_t Pipeline::GetUpdatePhase() const {
    return mOnUpdate;
}

ecs_entity_t Pipeline::GetDrawPhase() const {
    return mOnDraw;
}