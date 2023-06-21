# ArduinoJson - https://arduinojson.org
# Copyright © 2014-2023, Benoit BLANCHON
# MIT License

cmake_minimum_required(VERSION 3.15)

if(ESP_PLATFORM)
    # Build ArduinoJson as an ESP-IDF component

    set(headers
        src/ArduinoJson/Array/ElementProxy.hpp
        src/ArduinoJson/Array/JsonArrayConst.hpp
        src/ArduinoJson/Array/JsonArray.hpp
        src/ArduinoJson/Array/JsonArrayImpl.hpp
        src/ArduinoJson/Array/JsonArrayIterator.hpp
        src/ArduinoJson/Array/Utilities.hpp
        src/ArduinoJson/Collection/CollectionData.hpp
        src/ArduinoJson/Collection/CollectionImpl.hpp
        src/ArduinoJson/compatibility.hpp
        src/ArduinoJson/Configuration.hpp
        src/ArduinoJson/Deserialization/DeserializationError.hpp
        src/ArduinoJson/Deserialization/DeserializationOptions.hpp
        src/ArduinoJson/Deserialization/deserialize.hpp
        src/ArduinoJson/Deserialization/Filter.hpp
        src/ArduinoJson/Deserialization/NestingLimit.hpp
        src/ArduinoJson/Deserialization/Reader.hpp
        src/ArduinoJson/Deserialization/Readers/ArduinoStreamReader.hpp
        src/ArduinoJson/Deserialization/Readers/ArduinoStringReader.hpp
        src/ArduinoJson/Deserialization/Readers/FlashReader.hpp
        src/ArduinoJson/Deserialization/Readers/IteratorReader.hpp
        src/ArduinoJson/Deserialization/Readers/RamReader.hpp
        src/ArduinoJson/Deserialization/Readers/StdStreamReader.hpp
        src/ArduinoJson/Deserialization/Readers/VariantReader.hpp
        src/ArduinoJson/Document/BasicJsonDocument.hpp
        src/ArduinoJson/Document/DynamicJsonDocument.hpp
        src/ArduinoJson/Document/JsonDocument.hpp
        src/ArduinoJson/Document/StaticJsonDocument.hpp
        src/ArduinoJson.hpp
        src/ArduinoJson/Json/EscapeSequence.hpp
        src/ArduinoJson/Json/JsonDeserializer.hpp
        src/ArduinoJson/Json/JsonSerializer.hpp
        src/ArduinoJson/Json/Latch.hpp
        src/ArduinoJson/Json/PrettyJsonSerializer.hpp
        src/ArduinoJson/Json/TextFormatter.hpp
        src/ArduinoJson/Json/Utf16.hpp
        src/ArduinoJson/Json/Utf8.hpp
        src/ArduinoJson/Memory/Alignment.hpp
        src/ArduinoJson/Memory/MemoryPool.hpp
        src/ArduinoJson/Misc/SerializedValue.hpp
        src/ArduinoJson/MsgPack/endianess.hpp
        src/ArduinoJson/MsgPack/ieee754.hpp
        src/ArduinoJson/MsgPack/MsgPackDeserializer.hpp
        src/ArduinoJson/MsgPack/MsgPackSerializer.hpp
        src/ArduinoJson/Namespace.hpp
        src/ArduinoJson/Numbers/arithmeticCompare.hpp
        src/ArduinoJson/Numbers/convertNumber.hpp
        src/ArduinoJson/Numbers/FloatParts.hpp
        src/ArduinoJson/Numbers/FloatTraits.hpp
        src/ArduinoJson/Numbers/JsonFloat.hpp
        src/ArduinoJson/Numbers/JsonInteger.hpp
        src/ArduinoJson/Numbers/parseNumber.hpp
        src/ArduinoJson/Object/JsonObjectConst.hpp
        src/ArduinoJson/Object/JsonObject.hpp
        src/ArduinoJson/Object/JsonObjectImpl.hpp
        src/ArduinoJson/Object/JsonObjectIterator.hpp
        src/ArduinoJson/Object/JsonPair.hpp
        src/ArduinoJson/Object/MemberProxy.hpp
        src/ArduinoJson/Polyfills/alias_cast.hpp
        src/ArduinoJson/Polyfills/assert.hpp
        src/ArduinoJson/Polyfills/attributes.hpp
        src/ArduinoJson/Polyfills/ctype.hpp
        src/ArduinoJson/Polyfills/integer.hpp
        src/ArduinoJson/Polyfills/limits.hpp
        src/ArduinoJson/Polyfills/math.hpp
        src/ArduinoJson/Polyfills/mpl/max.hpp
        src/ArduinoJson/Polyfills/pgmspace_generic.hpp
        src/ArduinoJson/Polyfills/pgmspace.hpp
        src/ArduinoJson/Polyfills/preprocessor.hpp
        src/ArduinoJson/Polyfills/type_traits/conditional.hpp
        src/ArduinoJson/Polyfills/type_traits/declval.hpp
        src/ArduinoJson/Polyfills/type_traits/enable_if.hpp
        src/ArduinoJson/Polyfills/type_traits.hpp
        src/ArduinoJson/Polyfills/type_traits/integral_constant.hpp
        src/ArduinoJson/Polyfills/type_traits/is_array.hpp
        src/ArduinoJson/Polyfills/type_traits/is_base_of.hpp
        src/ArduinoJson/Polyfills/type_traits/is_class.hpp
        src/ArduinoJson/Polyfills/type_traits/is_const.hpp
        src/ArduinoJson/Polyfills/type_traits/is_convertible.hpp
        src/ArduinoJson/Polyfills/type_traits/is_enum.hpp
        src/ArduinoJson/Polyfills/type_traits/is_floating_point.hpp
        src/ArduinoJson/Polyfills/type_traits/is_integral.hpp
        src/ArduinoJson/Polyfills/type_traits/is_pointer.hpp
        src/ArduinoJson/Polyfills/type_traits/is_same.hpp
        src/ArduinoJson/Polyfills/type_traits/is_signed.hpp
        src/ArduinoJson/Polyfills/type_traits/is_unsigned.hpp
        src/ArduinoJson/Polyfills/type_traits/make_unsigned.hpp
        src/ArduinoJson/Polyfills/type_traits/make_void.hpp
        src/ArduinoJson/Polyfills/type_traits/remove_const.hpp
        src/ArduinoJson/Polyfills/type_traits/remove_cv.hpp
        src/ArduinoJson/Polyfills/type_traits/remove_reference.hpp
        src/ArduinoJson/Polyfills/type_traits/type_identity.hpp
        src/ArduinoJson/Polyfills/utility.hpp
        src/ArduinoJson/Serialization/CountingDecorator.hpp
        src/ArduinoJson/Serialization/measure.hpp
        src/ArduinoJson/Serialization/serialize.hpp
        src/ArduinoJson/Serialization/Writer.hpp
        src/ArduinoJson/Serialization/Writers/ArduinoStringWriter.hpp
        src/ArduinoJson/Serialization/Writers/DummyWriter.hpp
        src/ArduinoJson/Serialization/Writers/PrintWriter.hpp
        src/ArduinoJson/Serialization/Writers/StaticStringWriter.hpp
        src/ArduinoJson/Serialization/Writers/StdStreamWriter.hpp
        src/ArduinoJson/Serialization/Writers/StdStringWriter.hpp
        src/ArduinoJson/Strings/Adapters/FlashString.hpp
        src/ArduinoJson/Strings/Adapters/JsonString.hpp
        src/ArduinoJson/Strings/Adapters/RamString.hpp
        src/ArduinoJson/Strings/Adapters/StringObject.hpp
        src/ArduinoJson/Strings/IsString.hpp
        src/ArduinoJson/Strings/JsonString.hpp
        src/ArduinoJson/Strings/StoragePolicy.hpp
        src/ArduinoJson/Strings/StringAdapter.hpp
        src/ArduinoJson/Strings/StringAdapters.hpp
        src/ArduinoJson/Strings/StringTraits.hpp
        src/ArduinoJson/StringStorage/StringCopier.hpp
        src/ArduinoJson/StringStorage/StringMover.hpp
        src/ArduinoJson/StringStorage/StringStorage.hpp
        src/ArduinoJson/Variant/Converter.hpp
        src/ArduinoJson/Variant/ConverterImpl.hpp
        src/ArduinoJson/Variant/JsonVariantConst.hpp
        src/ArduinoJson/Variant/JsonVariant.hpp
        src/ArduinoJson/Variant/SlotFunctions.hpp
        src/ArduinoJson/Variant/VariantAttorney.hpp
        src/ArduinoJson/Variant/VariantCompare.hpp
        src/ArduinoJson/Variant/VariantContent.hpp
        src/ArduinoJson/Variant/VariantData.hpp
        src/ArduinoJson/Variant/VariantFunctions.hpp
        src/ArduinoJson/Variant/VariantImpl.hpp
        src/ArduinoJson/Variant/VariantOperators.hpp
        src/ArduinoJson/Variant/VariantRefBase.hpp
        src/ArduinoJson/Variant/VariantSlot.hpp
        src/ArduinoJson/Variant/VariantTag.hpp
        src/ArduinoJson/Variant/VariantTo.hpp
        src/ArduinoJson/Variant/Visitor.hpp
        src/ArduinoJson/version.hpp
    )

    set(sources
    )

    set(dependencies
    )

    idf_component_register(
        INCLUDE_DIRS
            src
        SRCS
            ${headers}
            ${sources}
        REQUIRES
            ${dependencies}
    )

    set_property(TARGET ${COMPONENT_LIB} PROPERTY CXX_STANDARD 23)

    target_compile_options(${COMPONENT_TARGET}
        PUBLIC
            -DARDUINOJSON_USE_LONG_LONG
            -DARDUINOJSON_ENABLE_STD_STRING=1
            -DARDUINOJSON_ENABLE_STRING_VIEW=1
            -DARDUINOJSON_ENABLE_ARDUINO_STRING=0
            -DARDUINOJSON_ENABLE_ARDUINO_STREAM=0
            -DARDUINOJSON_ENABLE_ARDUINO_PRINT=0
            -DARDUINOJSON_ENABLE_PROGMEM=0
            -DARDUINOJSON_NO_ARDUINO=1
    )

    return()
endif()

project(ArduinoJson VERSION 6.21.2)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
        include(CTest)
endif()

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
        include(extras/CompileOptions.cmake)
        add_subdirectory(extras/tests)
        add_subdirectory(extras/fuzzing)
endif()
