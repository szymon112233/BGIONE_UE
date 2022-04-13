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
		TestEqual(TEXT("Check slots count"), inv1->GetTotalSlotsCount(), size.X * size.Y);
		TestEqual(TEXT("Check free slots count"), inv1->GetFreeSlotsCount(), size.X * size.Y);
		TestEqual(TEXT("Check taken slots count"), inv1->GetTakenSlotsCount(), 0);
	}

	//item add and remove
	{
		UInventoryInstance* inv1 = NewObject<UInventoryInstance>();
		FIntPoint size = FIntPoint(2, 2);
		inv1->Initialize(size);

		UItemType* testItemType = NewObject<UItemType>();
		testItemType->Name = "testItem";
		testItemType->Size = FIntPoint(1,1);
		testItemType->IsStackable = true;
		testItemType->MaxStackSize = 10;
		
		UItemStackInstance* item1 = NewObject<UItemStackInstance>();
		item1->Initialise(testItemType, 1);
		
		TestEqual(TEXT("New inventories must be empty"), inv1->IsEmpty(), true);

		inv1->AddItem(item1, FIntPoint(0,0));

		TestEqual(TEXT("Inventory with added items cannot be empty"), inv1->IsEmpty(), false);
		TestEqual(TEXT("Check free slots count after adding item"), inv1->GetFreeSlotsCount(), size.X * size.Y -1);
		TestEqual(TEXT("Check taken slots count after adding item"), inv1->GetTakenSlotsCount(), 1);
		
		inv1->RemoveItemByReference(item1);

		TestEqual(TEXT("Inventory with removed all items should be empty"), inv1->IsEmpty(), true);
		TestEqual(TEXT("Check free slots count after removing item"), inv1->GetFreeSlotsCount(), size.X * size.Y);
		TestEqual(TEXT("Check taken slots count after removing item"), inv1->GetTakenSlotsCount(), 0);
	}

	//bigger items than 1x1
	{
		UInventoryInstance* inv1 = NewObject<UInventoryInstance>();
		FIntPoint size = FIntPoint(2, 2);
		inv1->Initialize(size);

		UItemType* testItemType = NewObject<UItemType>();
		testItemType->Name = "testItem";
		testItemType->Size = FIntPoint(1,2);
		testItemType->IsStackable = true;
		testItemType->MaxStackSize = 10;
		
		UItemStackInstance* item1 = NewObject<UItemStackInstance>();
		item1->Initialise(testItemType, 1);

		inv1->AddItem(item1, FIntPoint(0,0));
		
		TestEqual(TEXT("Check free slots count after adding item"), inv1->GetFreeSlotsCount(), size.X * size.Y -2);
		TestEqual(TEXT("Check taken slots count after adding item"), inv1->GetTakenSlotsCount(), 2);
		
		inv1->RemoveItemByReference(item1);
		
		TestEqual(TEXT("Check free slots count after removing item"), inv1->GetFreeSlotsCount(), size.X * size.Y);
		TestEqual(TEXT("Check taken slots count after removing item"), inv1->GetTakenSlotsCount(), 0);
	}
	
	return true;
}
