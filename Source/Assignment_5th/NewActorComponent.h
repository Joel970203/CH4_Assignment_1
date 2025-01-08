#pragma once // 헤더파일은 한번만 

#include "CoreMinimal.h" //UE 핵심 헤더파일 인클루드
#include "Components/ActorComponent.h" // 액터컴포넌트 클래스 
#include "NewActorComponent.generated.h" // Unreal Engine에서 자동으로 생성되는 코드에 포함된 헤더 파일

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASSIGNMENT_5TH_API UNewActorComponent : public UActorComponent
{
	GENERATED_BODY() // 매크로 

public:	
	// Sets default values for this component's properties
	UNewActorComponent();

protected:
	virtual void BeginPlay() override;

	int32 Step();
	void Move();
	bool CreateEvent();

private:
	FVector2D StartPosition;  // 시작 좌표
	int32 EventCount;         // 이벤트 발생 횟수
	float TotalDistance;      // 총 이동 거리

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};