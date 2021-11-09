#include <gtest/gtest.h>
#include <iostream>
#include <libmail-handle/mail_handle.hpp>

using namespace std;

// Test add Message to specific Folder
TEST(FolderTest, TestAddMessage) {
    string   msg = "Test Message";
    Folder   test_folder;
    Message* new_message = new Message(msg);

    // Add the message to test_folder
    test_folder.AddMsg(new_message);
    auto msg_list = test_folder.msg_list();

    // Check the test_folder has a message
    EXPECT_EQ(msg_list.size(), 1);

    // Check message's content is "Test Message"
    EXPECT_EQ(0, find_if(msg_list.begin(), msg_list.end(), [&msg](Message* m) {
                     return m->content() == msg;
                 }) == msg_list.end());
}

// Test remove message from  test_folder
TEST(FolderTest, TestRemoveMessage) {

    Folder test_folder;

    // Insert three message in test_folder
    Message* target_message = new Message("Test Mesage 2");
    test_folder.AddMsg(new Message("Test Message 1"));
    test_folder.AddMsg(target_message);
    test_folder.AddMsg(new Message("Test Message 3"));

    // Remove second message in test_folder
    test_folder.RemMsg(target_message);

    // Check test_folder have 2 message
    auto msg_list = test_folder.msg_list();
    EXPECT_EQ(msg_list.size(), 2);

    // Check remain message content is correctly
    auto it = msg_list.begin();
    EXPECT_STREQ((*it++)->content().data(), "Test Message 1");
    EXPECT_STREQ((*it)->content().data(), "Test Message 3");
}

// Test save/remove the message
TEST(MessageTest, TestSaveAndRemove) {

    Folder   test_folder;
    Message* test_message = new Message("Test Message");

    // Save the message (add the refference to each folder)
    test_message->Save(test_folder);

    // Check the folder have the message
    auto folders  = test_message->folders();
    auto msg_list = test_folder.msg_list();
    EXPECT_EQ(*folders.begin(), &test_folder);
    EXPECT_STREQ((*msg_list.begin())->content().data(), "Test Message");

    // Remove the message (remove all refference in each folder)
    test_message->Remove(test_folder);

    // Check the folder is empty
    folders  = test_message->folders();
    msg_list = test_folder.msg_list();
    EXPECT_EQ(folders.size(), 0);
    EXPECT_EQ(msg_list.size(), 0);
}

// Test copy constructor
TEST(MessageTest, TestCopyConstructor) {

    Folder test_folder;

    Message m("Test Message");
    m.Save(test_folder);

    Message m_copy(m);

    // Now test folder have two message
    EXPECT_EQ(test_folder.msg_list().size(), 2);
    for (auto m : test_folder.msg_list()) {
        EXPECT_STREQ(m->content().data(), "Test Message");
    }
}

// Test copy-assignment operator
TEST(MessageTest, TestCopyAssignment) {

    Folder test_folder;

    Message m("Test Message");
    m.Save(test_folder);

    Message lhs;
    lhs = m;

    // Now test folder have the same two message
    EXPECT_EQ(test_folder.msg_list().size(), 2);

    for (auto m : test_folder.msg_list()) {
        EXPECT_STREQ(m->content().data(), "Test Message");
    }
}

// Test destructor
TEST(MessageTest, TestDestructor) {

    Folder test_folder;

    Message* m = new Message("Test Message");
    m->Save(test_folder);

    // Now folder have a one message
    EXPECT_EQ(test_folder.msg_list().size(), 1);
    EXPECT_STREQ((*test_folder.msg_list().begin())->content().data(),
                 "Test Message");

    delete m;

    // Now test folder is empty
    EXPECT_EQ(test_folder.msg_list().size(), 0);
}

// Test Swap
TEST(MessageTest, TestSwap) {
    Folder work_folder;
    Folder school_folder;

    Message work_msg("Boss: you need to come to my office, now!");
    Message school_msg(
        "Abby: we have the operate system class on tomorrow, right?");

    work_msg.Save(work_folder);
    school_msg.Save(school_folder);

    Swap(work_msg, school_msg);

    EXPECT_STREQ(work_msg.content().data(),
                 "Abby: we have the operate system class on tomorrow, right?");

    EXPECT_STREQ(school_msg.content().data(),
                 "Boss: you need to come to my office, now!");

    // Folder had to keep the correct msg
    EXPECT_STREQ((**work_folder.msg_list().begin()).content().data(),
                 "Boss: you need to come to my office, now!");

    EXPECT_STREQ((**school_folder.msg_list().begin()).content().data(),
                 "Abby: we have the operate system class on tomorrow, right?");
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
