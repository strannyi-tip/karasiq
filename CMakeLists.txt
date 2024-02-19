cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME karasiq)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH "/usr/include/x86_64-linux-gnu/qt6")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++20")
set(QT_VERSION 5)
set(QT_VERSION_MAJOR 6)
set(REQUIRED_LIBS Core Gui Widgets Network)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

find_package(SqliteOrm 1.8.0 REQUIRED)

set(${PROJECT_NAME} PROJECT_SOURCES
       include/Resources.hpp
)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
find_package(nlohmann_json)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES}
        main.cpp
        include/Core/MainWindow.hpp
        src/Core/MainWindow.cpp
        include/Graphics/CSSableWidget.hpp
        src/Graphics/CSSableWidget.cpp
        include/Component/ChatContactFactory.hpp
        src/Component/ChatContactFactory.cpp
        include/Component/RandomIDGenerator.hpp
        src/Component/RandomIDGenerator.cpp
        include/Component/EntitySchemaContainer.hpp
        include/Component/EntitySchema.hpp
        include/Component/FontDatabase.hpp
        src/Component/FontDatabase.cpp
        include/Entity/UserEntity.hpp
        include/Entity/ContactFindDataEntity.hpp
        include/Entity/ContactAddDataEntity.hpp
        include/Component/EntitySerializer.hpp
        src/Component/EntitySerializer.cpp
        include/Core/SocketClient.hpp
        src/Core/SocketClient.cpp
        include/Component/Sqlite3SomeQuery.hpp
        src/Component/Sqlite3SomeQuery.cpp
        include/Component/QtMethodLogger.hpp
        src/Component/QtMethodLogger.cpp
        include/Component/AbstractLogger.hpp
        src/Component/AbstractLogger.cpp
        include/Test/AbstractTest.hpp
        include/Test/LoggerTest.hpp
        src/Test/LoggerTest.cpp
        tests/tests.hpp
        include/Component/ChatMessageFactory.hpp
        src/Component/ChatMessageFactory.cpp
        include/Component/Authenticator.hpp
        src/Component/Authenticator.cpp
        include/Component/PasswordHasher.hpp
        src/Component/PasswordHasher.cpp
        include/Component/AuthTokenCreator.hpp
        src/Component/AuthTokenCreator.cpp
        include/Graphics/PasswordInput.hpp
        src/Graphics/PasswordInput.cpp
        include/Graphics/VSpase.hpp
        src/Graphics/VSpase.cpp
        include/Entity/SystemEntity.hpp
        include/Entity/UserInfoEntity.hpp
        include/Entity/ContactEntity.hpp
        include/Entity/ExtendedStatusEntity.hpp
        include/Entity/ProgLangEntity.hpp
        include/Graphics/MainWidget.hpp
        src/Graphics/MainWidget.cpp
        include/Graphics/ChatMessageWidget.hpp
        src/Graphics/ChatMessageWidget.cpp
        include/Graphics/StatusMessageWidget.hpp
        src/Graphics/StatusMessageWidget.cpp
        include/Graphics/WindowPanel.hpp
        src/Graphics/WindowPanel.cpp
        include/View/ChatView.hpp
        src/View/ChatView.cpp
        include/Graphics/ChatContactsWidget.hpp
        src/Graphics/ChatContactsWidget.cpp
        include/Graphics/ChatBodyWidget.hpp
        src/Graphics/ChatBodyWidget.cpp
        include/Graphics/StyledButton.hpp
        src/Graphics/StyledButton.cpp
        include/Graphics/ContactsSortWidget.hpp
        src/Graphics/ContactsSortWidget.cpp
        include/Graphics/ChatOptionsWidget.hpp
        src/Graphics/ChatOptionsWidget.cpp
        include/Graphics/ExtendedStatusWidget.hpp
        src/Graphics/ExtendedStatusWidget.cpp
        include/Graphics/TextArea.hpp
        src/Graphics/TextArea.cpp
        include/Graphics/ChatMessagesAreaWidget.hpp
        src/Graphics/ChatMessagesAreaWidget.cpp
        include/Graphics/ChatControlsAreaWidget.hpp
        src/Graphics/ChatControlsAreaWidget.cpp
        include/Graphics/ListWidget.hpp
        src/Graphics/ListWidget.cpp
        include/Graphics/VerticalScrollBar.hpp
        src/Graphics/VerticalScrollBar.cpp
        include/Core/DatabasePreloader.hpp
        src/Core/DatabasePreloader.cpp
        include/Graphics/MainMenu.hpp
        src/Graphics/MainMenu.cpp
        include/View/SettingsView.hpp
        src/View/SettingsView.cpp
        include/Graphics/LabeledInput.hpp
        src/Graphics/LabeledInput.cpp
        include/Graphics/LabeledPasswordInput.hpp
        src/Graphics/LabeledPasswordInput.cpp
        include/Graphics/DropDownList.hpp
        src/Graphics/DropDownList.cpp
        include/Graphics/DropDownButton.hpp
        src/Graphics/DropDownButton.cpp
        include/Graphics/DropDownBody.hpp
        src/Graphics/DropDownBody.cpp
        include/Core/SystemPreloader.hpp
        src/Core/SystemPreloader.cpp
        include/Graphics/ContactSearchWidget.hpp
        src/Graphics/ContactSearchWidget.cpp
        include/Graphics/ListGroup.hpp
        src/Graphics/ListGroup.cpp
        include/Graphics/DialogTabs.hpp
        src/Graphics/DialogTabs.cpp
        include/View/DialogTabView.hpp
        src/View/DialogTabView.cpp
        include/Graphics/TabCloseButton.hpp
        src/Graphics/TabCloseButton.cpp
        src/Component/EntityFixture.cpp
        include/Graphics/ContactList.hpp
        src/Graphics/ContactList.cpp
        include/Graphics/ContactListItem.hpp
        src/Graphics/ContactListItem.cpp
        include/Graphics/DropDownContactList.hpp
        src/Component/DropDownContactList.cpp
        include/Interface/Countable.hpp
        include/Graphics/Select.hpp
        src/Graphics/Select.cpp
        include/Graphics/SelectItem.hpp
        src/Graphics/SelectItem.cpp
        include/Component/SelectItemFactory.hpp
        src/Graphics/SelectItemFactory.cpp
        include/Graphics/SelectHead.hpp
        src/Graphics/SelectHead.cpp
        include/Graphics/SelectBody.hpp
        src/Graphics/SelectBody.cpp
        include/Component/SequentlyIDGenerator.hpp
        src/Component/SequentlyIDGenerator.cpp
        include/Core/Loader.hpp
        src/Core/Loader.cpp
        include/Graphics/LoadingProgress.hpp
        src/Graphics/LoadingProgress.cpp
        src/Core/Loader.cpp
        include/Core/Connection.hpp
        include/Graphics/AnimatedWidget.hpp
        src/Graphics/AnimatedWidget.cpp
        include/Struct/Animation.hpp
        include/Graphics/MainMenuItem.hpp
        src/Graphics/MainMenuItem.cpp
        include/Graphics/AuthenticatorWidget.hpp
        src/Graphics/AuthenticatorWidget.cpp
        include/Component/ConnectionWrapper.hpp
        src/Component/ConnectionWrapper.cpp
        include/Graphics/HSpase.hpp
        src/Graphics/HSpase.cpp
        include/Graphics/ClickableLabel.hpp
        src/Graphics/ClickableLabel.cpp
)

target_link_libraries (${PROJECT_NAME} PRIVATE ${REQUIRED_LIBS_QUALIFIED} nlohmann_json::nlohmann_json sqlite_orm::sqlite_orm)
