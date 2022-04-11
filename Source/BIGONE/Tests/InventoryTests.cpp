#include "BIGONE/Inventory/InventoryInstance.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(InventoryTests, "BIGONE.BIGONE.Tests.InventoryTests",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool InventoryTests::RunTest(const FString& Parameters)
{

	//Size test
	{
		UInventoryInstance* inv1 = NewObject<UInventoryInstance>();
		FIntPoint size = FIntPoint(2, 2);
		inv1->Initialize(size);
		
		TestEqual(TEXT("New inventories must be empty"), inv1->IsEmpty(), true);
		TestEqual(TEXT("Check x size"), inv1->GetInventorySize().X, size.X);
		TestEqual(TEXT("Check y size"), inv1->GetInventorySize().Y, size.Y);
	}
	
	return true;
}
