// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0+ OR GPL-3.0 WITH Qt-GPL-exception-1.0

#pragma once

#include "theme.h"

#include <utils/stylehelper.h>

#include <QIcon>

namespace QmlDesigner {

class DesignerIconsPrivate;

class IconFontHelper : public Utils::StyleHelper::IconFontHelper
{
    typedef Utils::StyleHelper::IconFontHelper Super;

public:
    IconFontHelper(Theme::Icon themeIcon,
                   Theme::Color color,
                   const QSize &size,
                   QIcon::Mode mode = QIcon::Normal,
                   QIcon::State state = QIcon::Off);

    static IconFontHelper fromJson(const QJsonObject &jsonObject);
    QJsonObject toJson() const;
    Theme::Icon themeIcon() const;
    Theme::Color themeColor() const;

private:
    IconFontHelper();

    Theme::Icon mThemeIcon;
    Theme::Color mThemeColor;
};

class DesignerIcons
{
    Q_GADGET
    friend DesignerIconsPrivate;

public:
    enum IconId {
        AddMouseAreaIcon,
        AlignBottomIcon,
        AlignLeftIcon,
        AlignRightIcon,
        AlignTopIcon,
        AnchorsIcon,
        AnnotationIcon,
        ArrangeIcon,
        ConnectionsIcon,
        EditIcon,
        EnterComponentIcon,
        EventListIcon,
        GroupSelectionIcon,
        LayoutsIcon,
        MakeComponentIcon,
        MergeWithTemplateIcon,
        PositionsersIcon,
        SelecionIcon,
        SnappingIcon,
        TimelineIcon,
        ShowBoundsIcon,
        VisibilityIcon
    };
    Q_ENUM(IconId)

    enum Area {
        TopToolbarArea,
        ContextMenuArea
    };
    Q_ENUM(Area)

    enum Mode {
        Normal = QIcon::Normal,
        Disabled = QIcon::Disabled,
        Hovered = QIcon::Active,
        Selected = QIcon::Selected
    };

    Q_ENUM(Mode)

    enum State {
        Off = QIcon::Off,
        On = QIcon::On
    };
    Q_ENUM(State)

    typedef QMap<Mode, IconFontHelper> ModeMap;
    typedef QMap<State, ModeMap> IconMap;
    typedef QMap<Area, IconMap> AreaMap;
    typedef QMap<IconId, AreaMap> IconsMap;

    explicit DesignerIcons(const QString &fontName,
                           const QString &iconDatabase = QString());

    ~DesignerIcons();

    QIcon icon(IconId icon, Area area) const;

    void loadIconSettings(const QString &fileName);
    void exportSettings(const QString &fileName) const;

    void clearAll();
    void addIcon(const IconId &iconId,
                 const Area &area,
                 const IconFontHelper &fontHelper);

    void addIcon(IconId iconId,
                 Area area,
                 QIcon::Mode mode,
                 QIcon::State state,
                 Theme::Icon themeIcon,
                 Theme::Color color,
                 const QSize &size);

    void addIcon(IconId iconId,
                 Area area,
                 Theme::Icon themeIcon,
                 Theme::Color color,
                 const QSize &size);

private:
    QList<Utils::StyleHelper::IconFontHelper> helperList(const IconId &iconId,
                                                         const Area &area) const;

    DesignerIconsPrivate *d = nullptr;
};

}