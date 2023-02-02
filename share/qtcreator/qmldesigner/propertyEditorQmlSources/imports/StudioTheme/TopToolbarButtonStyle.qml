// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0 WITH Qt-GPL-exception-1.0

import QtQuick

ControlStyle {

    controlSize: Qt.size(Values.topLevelComboWidth, Values.topLevelComboHeight)
    baseIconFontSize: Values.topLevelComboIcon
    radius: Values.smallRadius

    icon: ControlStyle.IconColors {
        idle: Values.themeTextColor
        hover: Values.themeTextColor
        interaction: Values.themeTextSelectedTextColor
        disabled: "#636363"
    }

    background: ControlStyle.BackgroundColors {
        idle: Values.themeControlBackground_toolbarIdle
        hover: Values.themeControlBackground_topToolbarHover
        globalHover: Values.themeControlBackground_topToolbarHover
        interaction: Values.themeInteraction
        disabled: Values.themeControlBackground_toolbarIdle
    }

    border: ControlStyle.BorderColors {
        idle: Values.themeControlBackground_toolbarIdle
        hover: Values.themeControlBackground_toolbarHover
        interaction: Values.themeInteraction
        disabled: Values.themeControlBackground_toolbarIdle
    }
}