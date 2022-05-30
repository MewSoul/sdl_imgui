
#ifndef SDL_IMGUI_PIPELINE_H
#define SDL_IMGUI_PIPELINE_H

#include <flecs.h>

struct Pipeline {
public:
    explicit Pipeline(ecs_world_t *pWorld);
    ecs_entity_t GetPipeline() const;
    ecs_entity_t GetInputPhase() const;
    ecs_entity_t GetUpdatePhase() const;
    ecs_entity_t GetDrawPhase() const;

private:
    ecs_entity_t mOnInput;
    ecs_entity_t mOnUpdate;
    ecs_entity_t mOnDraw;

    ecs_entity_t mPipeline;
};


#endif //SDL_IMGUI_PIPELINE_H
