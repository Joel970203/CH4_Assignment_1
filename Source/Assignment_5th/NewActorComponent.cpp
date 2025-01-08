#include "NewActorComponent.h"
#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Vector2D.h"

UNewActorComponent::UNewActorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    EventCount = 0;          // 초기화
    TotalDistance = 0.0f;    // 초기화
}

void UNewActorComponent::BeginPlay()
{
    Super::BeginPlay();
    Move();
}

int32 UNewActorComponent::Step()
{
    return FMath::RandRange(0, 1);  
}

bool UNewActorComponent::CreateEvent()
{
    // 50% 확률로 이벤트가 발생
    return FMath::RandBool();
}

void UNewActorComponent::Move()
{
    FVector2D Position(0, 0);  
    FVector2D LastPosition = Position; 

    for (int32 StepCount = 0; StepCount < 10; StepCount++)
    {
        int32 X = Step();
        int32 Y = Step();

        // 이동
        Position.X += X;
        Position.Y += Y;

        // 이벤트 발생 여부 확인
        bool bEventOccurred = CreateEvent();
		
        if (bEventOccurred)
        {
            EventCount++;  

            // 이벤트가 발생했을 때만 이동 거리 출력
            float DeltaX = Position.X - LastPosition.X;
            float DeltaY = Position.Y - LastPosition.Y;
            float Distance = FMath::Sqrt(DeltaX * DeltaX + DeltaY * DeltaY);  

            TotalDistance += Distance;  // 이동 거리를 총 이동 거리 변수에 더함

            UE_LOG(LogTemp, Log, TEXT("Step %d: Position (%.2f, %.2f), Distance: %.2f"),
                StepCount + 1, Position.X, Position.Y, Distance);
        }
        else
        {
            // 이벤트가 발생하지 않았을 때는 그냥 좌표만 출력
            UE_LOG(LogTemp, Log, TEXT("Step %d: Position (%.2f, %.2f)"),
                StepCount + 1, Position.X, Position.Y);
        }

        LastPosition = Position;
    }
    
    // 총 이동 거리 및 이벤트 발생 횟수 출력
    UE_LOG(LogTemp, Log, TEXT("Total Distance: %.2f, Total Events: %d"), TotalDistance, EventCount);
}

void UNewActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}