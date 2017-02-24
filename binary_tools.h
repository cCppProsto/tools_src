#ifndef BINARY_TOOLS_H
#define BINARY_TOOLS_H

// https://wiki.qt.io/Doxygen_Plugin_for_QtCreator

/*!
 *  print value(char type) in binary representation to the console
 *
 *  @param[in]  aValue   The value
 *  @param[in]  aIsEndl  The flag, if aIsEndl == 1 after print binary representation
 *                       inserts a newline
 */
void bt_print_1b(char aValue, char aIsEndl);

/*!
 *  print value(char type) in binary representation to the console
 *
 *  @param[in]  aValue     The value
 *  @param[in]  aMarkIndex The bit number which need to mark
 *  @param[in]  aIsEndl    The flag, if aIsEndl == 1 after print binary representation
 *                         inserts a newline
 */
void bt_print_mark_1b(char aValue, unsigned char aMarkIndex, char aIsEndl);

/*!
 *  print value(short type) in binary representation to the console
 *
 *  @param[in]  aValue   The value
 *  @param[in]  aIsEndl  The flag, if aIsEndl == 1 after print binary representation
 *                       inserts a newline
 */
void bt_print_2b(short aValue, char aIsEndl);

/*!
 *  print value(short type) in binary representation to the console
 *
 *  @param[in]  aValue     The value
 *  @param[in]  aMarkIndex The bit number which need to mark
 *  @param[in]  aIsEndl    The flag, if aIsEndl == 1 after print binary representation
 *                         inserts a newline
 */
void bt_print_mark_2b(short aValue, unsigned char aMarkIndex, char aIsEndl);

/*!
 *  print value(int type) in binary representation to the console
 *
 *  @param[in]  aValue   The value
 *  @param[in]  aIsEndl  The flag, if aIsEndl == 1 after print binary representation
 *                       inserts a newline
 */
void bt_print_4b(int aValue, char aIsEndl);

/*!
 *  print value(int type) in binary representation to the console
 *
 *  @param[in]  aValue     The value
 *  @param[in]  aMarkIndex The bit number which need to mark
 *  @param[in]  aIsEndl    The flag, if aIsEndl == 1 after print binary representation
 *                         inserts a newline
 */
void bt_print_mark_4b(int aValue, unsigned char aMarkIndex, char aIsEndl);

/*!
 *  check a value is even or not
 *
 *  @param[in]  aValue   value which need to check
 *
 *  @return 1 if aValue is even
 */
char bt_isEven(int aValue);

/*!
 *  check a value is odd or not
 *
 *  @param[in]  aValue   value which need to check
 *
 *  @return 1 if aValue is odd
 */
char bt_isOdd(int aValue);

/*!
 *  invert specific bit
 *
 *  @param[in]  aValue   The value
 *  @param[in]  aIndex   number a specific bit
 *  @return     the changed aValue
 */
int bt_invert_bit(int aValue, unsigned char aIndex);

/*!
 *  set in 1 specific bit
 *
 *  @param[in]  aValue   The value
 *  @param[in]  aIndex   number a specific bit
 *  @return     the changed aValue
 */
int bt_set_bit(int aValue, unsigned char aIndex);

/*!
 *  clear in 1 specific bit
 *
 *  @param[in]  aValue   The value
 *  @param[in]  aIndex   number a specific bit
 *  @return     the changed aValue
 */
int bt_clear_bit(int aValue, unsigned char aIndex);

/*!
 *  test specific bit
 *
 *  @param[in]  aValue   The value
 *  @param[in]  aIndex   number a specific bit
 *  @return     1 if specific bit is a 1 else 0
 */
int bt_test_bit(int aValue, unsigned char aIndex);

#endif // BINARY_TOOLS_H
